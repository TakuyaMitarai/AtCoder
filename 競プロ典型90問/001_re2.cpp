#include <iostream>
using namespace std;

int N, L, K;
int A[1 << 20];

bool desc(int m) 
{
    int pre = 0;
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        if(A[i] - pre >= m && L - A[i] >= m) {
            cnt++;
            pre = A[i];
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
        cin >> A[i];
    }

    int left = -1, right = L + 1;

    while(right - left > 1) {
        int mid = (right + left) / 2;
        if(desc(mid) == true) left = mid;
        else right = mid;
    }

    cout << left << endl;
    return 0;
}