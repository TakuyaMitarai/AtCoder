#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long N, K;
string S;
vector<int> V;

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
                int b = V[min];
                V[min] = V[max];
                V[max] = b;
                min++;
                max--;
            }
        } while(min <= max);
        sort(m, max);
        sort(min, M);
    }
}

void k_sort(int m, int M)
{
    if(m < M) {
        long long min = m, max = M;
        long long mid = (min + max) / 2;
        long long d = V[mid];
        do {
            while(V[min] < d) {
                min++;
            }
            while(V[max] > d) {
                max--;
            }
            if(min <= max){
                int a = S[min];
                S[min] = S[max];
                S[max] = a;
                int b = V[min];
                V[min] = V[max];
                V[max] = b;
                min++;
                max--;
            }
        } while(min <= max);
        k_sort(m, max);
        k_sort(min, M);
    }
}

int main()
{
    cin >> N >> K >> S;
    for(int i = 0; i < N; i++) {
        V.push_back(i);
    }

    sort(0, N-1);
    k_sort(0,K-1);

    for(int i = 0; i < K; i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}