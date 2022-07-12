#include <iostream>
using namespace std;

long long N, B, K;
int c[10];
long long dp[10001][31];

int main()
{
    //入力
    cin >> N >> B >> K;
    for(int i = 0; i < K; i++) {
        cin >> c[i];
    }

    //動的計画法
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < B; j++) {
            for(int k = 0; k < K; k++) {
                int nex = (10 * j + c[k]) % B;
                dp[i][nex] += dp[i - 1][j];
                dp[i][nex] %= 1000000007;
            }
        }
    }

    //出力
    cout << dp[N][0] << endl;
}