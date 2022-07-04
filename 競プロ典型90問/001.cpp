#include <iostream>
using namespace std;

long long n, k, l;
long long a[1 << 17];

bool disc(long long m) {
    long long cnt = 0, pre = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] - pre >= m && l - a[i] >= m) {
            cnt++;
            pre = a[i];
        }
    }
    if(cnt >= k) return true;
    else return false;
}

int main()
{
    //入力
    cin >> n >> l >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long left = 0;
    long long right = l + 1;
    long long mid;
    
    while(right - left > 1) {
        mid = left + (right - left) / 2;
        if(disc(mid) == true) left = mid;
        else right = mid;
    }
    cout << left << endl;
}