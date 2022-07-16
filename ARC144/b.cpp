#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

long long N, a, b;
long long A[1 << 20];

bool desc(long long mid)
{
    long long cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(mid > A[i]) {
            cnt += (mid - A[i]) / a + 1;
            if((mid - A[i]) % a == 0) cnt--;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(mid + b <= A[i]) {
            cnt -= (A[i] - mid) / b;
        }
    }
    if(cnt <= 0) return true;
    else return false;
}

int main()
{
    //入力
    cin >> N >> a >> b;
    long long max = 0, min = 10000000000;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        if(A[i] > max) {
            max = A[i];
        }
        if(A[i] < min) {
            min = A[i];
        }
    }

    long long left = min - 1, right = max + 1;
    long long mid;

    while(right - left > 1) {
        mid = (right + left) / 2;
        if(desc(mid) == true) left = mid;
        else right = mid;
    }
    cout << left << endl;
}