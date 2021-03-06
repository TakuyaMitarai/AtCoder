#include <iostream>
using namespace std;

long long N, B, K;
int c[11]; 
long long dp[1 << 14][1 << 11];

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
        for(int k = 0; k < B; k++) {
            for(int j = 0; j < K; j++) {
                int nex = (10 * k + c[j]) % B;
                dp[i][nex] += dp[i - 1][k];
                dp[i][nex] %= 1000000007;
            }
        }
    }

    //出力
    cout << dp[N][0] << endl;
    return 0;
}