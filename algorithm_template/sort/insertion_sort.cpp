#include <iostream>
using namespace std;

long long N;
long long A[1 << 17];

void insertion_sort(long long m, long long M, long long A[])
{
    for(int i = m; i <= M; i++) {
        int v = A[i];
        int j = i - 1;
        while(j >= m && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main()
{
    //入力
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    insertion_sort(1, N, A);

    //出力
    for(int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}