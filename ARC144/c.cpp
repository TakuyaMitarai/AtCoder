#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    long long N, K;
    long long cnt1 = 1, cnt2;
    //入力
    cin >> N >> K;

    cnt2 = K + 1;

    long long now = cnt2;

    for(int i = 1; i <= N; i++) {
        if(cnt1 - i >= K || i - cnt1 >= K) {
            if(cnt1 != K + 1) {
                cout << cnt1 << " ";
                cnt1++;
            }
        } else if(cnt2 - i >= K || i - cnt2 >= K) {
            if(cnt2 != N + 1) {
                cout << cnt2 << " ";
                cnt2++;
            }
        }
        cout << "a" <<  i << "a ";
    }
    //出力
    cout << endl;
    return 0;
}