#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <double> S;

//逆ポーランド記法
int main()
{
    string a;

    //入力
    cin >> a;

    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '+') {
            double x = S.top();
            S.pop();
            double y = S.top();
            S.pop();
            S.push(x + y);
        } else if(a[i] == '-') {
            double x = S.top();
            S.pop();
            double y = S.top();
            S.pop();
            S.push((y - x));
        } else if(a[i] == '*') {
            double x = S.top();
            S.pop();
            double y = S.top();
            S.pop();
            S.push(x * y);
        } else if(a[i] == '/') {
            double x = S.top();
            S.pop();
            double y = S.top();
            S.pop();
            S.push(y / x);
        } else {
            S.push(a[i] - 48);
        }
    }

    //出力
    cout << S.top() << endl;
    return 0;
}