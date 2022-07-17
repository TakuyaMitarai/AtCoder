#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    string S;
    //入力
    cin >> S;
    //出力
    if(S[0] != S[1] && S[0] != S[2]) cout << S[0];
    else if(S[1] != S[2] && S[1] != S[0]) cout << S[1];
    else if(S[2] != S[0] && S[2] != S[1]) cout << S[2];
    else cout << "-1";
    cout << endl;
    return 0;
}