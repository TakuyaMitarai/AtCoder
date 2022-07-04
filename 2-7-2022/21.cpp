#include <iostream>
using namespace std;

int main()
{
    int a;
    int b = 21;

    cin >> a;

    if(a >= 60) {
        a -= 60;
        b++;
    }
    if(a<10){
        cout << b << ":0" << a;
    }else {
        cout << b << ":" << a;
    }
    return 0;
}