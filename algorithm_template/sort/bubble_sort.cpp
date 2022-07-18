#include <iostream>
using namespace std;

long long N;
long long A[1 << 17];

void bubble_sort(int m, int M, long long A[])
{
    int flag = 1;
    while(flag) {
        flag = 0;
        for(int i = M; i > m; i--) {
            if(A[i] < A[i-1]) {
                int b = A[i-1];
                A[i-1] = A[i];
                A[i] = b;
                flag = 1;
            }
        }
    }
}

int main() 
{
     //入力
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    bubble_sort(1, N, A);

    //出力
    for(int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}