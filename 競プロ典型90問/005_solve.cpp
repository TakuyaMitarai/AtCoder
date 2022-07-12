#include <iostream>
#include <queue>
using namespace std;

long long N, B, K;
int c[9]; 
long long dp[1 << 6][1 << 10];
queue<long long> Q;

int main() 
{
    //入力
    cin >> N >> B >> K;
    for(int i = 0; i < K; i++) {
        cin >> c[i];
    }

    //前処理
    for(int i = 1; i < B; i++) {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    
    //動的計画法
    for(int i = 1; i <= N; i++) {
        for(int k = 0; k < B; k++) {
            for(int j = 0; j < K; j++) {
                int nex = (10 * k + c[j]) % B;
                dp[i][nex] += dp[i - 1][k];
                cout << (10 * k + c[j]) % B << " " << k << c[j] << " " << dp[i][nex] << endl;
            }
        }
    }

    //出力
    cout << dp[N][0] << endl;
    return 0;
}