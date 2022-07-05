#include <iostream>
using namespace std;

long long N, L, K;
long long a[1 << 20];

bool desc(long long mid)
{
    long long cnt = 0;
    long long a1 =0;

    for(int i = 0; i < N; i++) {
        if(a[i] - a1 >= mid && L - a[i] > mid) {
            cnt++;
            a1 = a[i];
        }
    }
    if(cnt >= K) return true;
    else return false;
}

int main()
{
    //入力
    cin >> N >> L >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long left = -1, right = L;
    long long mid;

    while(right - left > 1) {
        mid = (right + left) / 2;
        if(desc(mid) == true) left = mid;
        else right = mid;
    }
    cout << left << endl;
}