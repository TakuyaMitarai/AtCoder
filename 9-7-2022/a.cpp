#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    long long N, M, X, T, D;
    //入力
    cin >> N >> M >> X >> T >> D;

    int s = 0;

    if(X <= M) {
        cout << T;
    }else{
        cout << T - D * (X -M) << endl;
    }
    return 0;
}