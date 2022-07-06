#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long N;
long long A[1 >> 20];
long long B[1 >> 20];
vector<int> P[1 >> 20];
int cnt[1 >> 20];

void minmax(int s)
{   
    for(int i = 1; i <= N; i++) cnt[i] = -1;
    int pos;
    queue<int> Q;
    Q.push(s);
    cnt[pos] = 0;

    while(!Q.empty()) {
        pos = Q.front();
        Q.pop();
        for(int i : P[pos]) {
            if(cnt[i] == -1) {
                cnt[i] = cnt[pos] + 1;
                Q.push(i);
            }
        }
    }
}

int main() 
{
    int max = 0;
    int max_num;
    //入力
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        P[A[i]].push_back(B[i]);
        P[B[i]].push_back(A[i]);
    }

    minmax(1);
    for(int i = 1; i <= N; i++) {
        if(cnt[i] >= max) {
            max = cnt[i];
            max_num = i;
        }
    }
    cout << max_num << endl;
    max = 0;

    minmax(max_num);
    for(int i = 1; i <= N; i++) {
        if(cnt[i] >= max) {
            max = cnt[i];
        }
    }
    cout << max + 1 << endl;
    return 0;
}