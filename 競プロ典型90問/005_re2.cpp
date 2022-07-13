#include <iostream>
using namespace std;

int main() 
{
    long long N, B, K;
    int c[10];

    //入力
    cin >> N >> B >> K;
    for(int i = 0; i < K; i++) {
        cin >> c[i];
    } 
    long long dp[10001][31];

    dp[0][0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < B; j++) {
            for(int k = 0; k < K; k++) {
                int x = (10 * j + c[k]) % B;
                dp[i][x] += dp[i - 1][j];
                dp[i][x] %= 1000000007;
            }
        }
    }

    //出力
    cout << dp[N][0] << endl;
    return 0;
}