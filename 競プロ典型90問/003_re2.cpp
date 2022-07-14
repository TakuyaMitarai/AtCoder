#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long N;
long long A[1 << 17], B[1 << 17];
vector<long long> P[1 << 17];
long long cnt[1 << 17];

void minmax(long long s)
{
    for(int i = 1; i <= N; i++) {
        cnt[i] = -1;
    }
    cnt[s] = 0;
    queue<long long> Q;
    Q.push(s);
    while(!Q.empty()){
        long long now = Q.front();
        Q.pop();
        for(int i : P[now]){
            if(cnt[i] == -1) {
                cnt[i] = cnt[now] + 1;
                Q.push(i);
            }
        }
    }
}
int main() 
{
    cin >> N;
    for(int i = 1; i <= N -1; i++) {
        cin >> A[i] >> B[i];
        P[A[i]].push_back(B[i]);
        P[B[i]].push_back(A[i]);
    }

    minmax(1);
    long long max = 0, max_num;
    for(int i = 1; i <= N; i++) {
        if(max <= cnt[i]) {
            max = cnt[i];
            max_num = i;
        }
    }
    max = 0;

    minmax(max_num);
    for(int i = 1; i <= N; i++) {
        if(max <= cnt[i]) {
            max = cnt[i];
            max_num = i;
        }
    }
    cout << max + 1 << endl;
    return 0;
}