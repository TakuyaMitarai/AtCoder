#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    long long N;
    //ε₯ε
    cin >> N;

    //εΊε
    cout << 2 * N << endl;

    int syou, amari;
    syou = N / 4;
    amari = N % 4;

    if(amari != 0) cout << amari;
    for(int i = 0; i < syou; i++) {
        cout << "4";
    }
    cout << endl;
    return 0;
}