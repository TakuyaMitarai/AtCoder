#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

long long N, X, Y;

int main()
{
    //入力
    cin >> N >> X >> Y;

    long long asum[12];
    long long bsum[12];
    asum[N] = 1;
    bsum[N] = 0;

    for(int n = N - 1; n >= 1; n-=1) {
        asum[n] = asum[n+1];
        bsum[n+1] += asum[n + 1] * X;
        asum[n] += bsum[n+1];
        bsum[n] = bsum[n+1] * Y;
    }
    //出力
    cout << bsum[1] << endl;
}