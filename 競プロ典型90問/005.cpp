#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long N, B, K;
long long C[10];
long long cnt = 0;

int main()
{
    //入力
    cin >> N >> B >> K;
    for(long long i = 1; i <= K; i++) {
        cin >> C[i];
    }
    long long n_num;
    if((long long)pow(10, N-1) % B == 0) {
        n_num = pow(10, N -1);
    } else {
        n_num = pow(10, N -1) + B - (long long)pow(10, N-1) % B;
    }

    for(; n_num < pow(10, N); n_num += B) {
        string s = to_string(n_num);
        long long cnt1 = 0;
        for(long long j = 0; j < N; j++) {
            for(long long i = 1; i <= K; i++) {
                if((long long)s[j] - 48 == C[i]) {
                    cnt1++;
                    break;
                }
            }
            if(cnt1 == N) cnt++;
        }
    }
    //出力
    cout << cnt << endl;
}