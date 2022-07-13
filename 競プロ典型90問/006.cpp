#include <iostream>
#include <string>
using namespace std;

long long N, K;
string S;

void sort(int m, int M)
{
    if(m < M) {
        long long min = m, max = M;
        long long mid = (min + max) / 2;
        char d = S[mid];
        do {
            while(S[min] < d) {
                min++;
            }
            while(S[max] > d) {
                max--;
            }
            if(min <= max){
                int a = S[min];
                S[min] = S[max];
                S[max] = a;
                min++;
                max--;
            }
        } while(min <= max);
        sort(m, max);
        sort(min, M);
    }
}

int main()
{
    cin >> N >> K >> S;
    sort(0, N-1);

    for(int i = 0; i < K; i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}