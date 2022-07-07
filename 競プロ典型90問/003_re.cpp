#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int A[1 << 20], B[1 << 20];
vector<int> P[1 << 20];
int cnt[1 << 20];

void minmax(int s)
{
    for(int i = 1; i <= N; i++) {
        cnt[i] = -1;
    }
    queue<int> Q;
    Q.push(s);
    cnt[s] = 0;

    while(!Q.empty()) {
        int pos = Q.front();
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
    //入力
    cin >> N;
    for(int i = 1; i <= N - 1; i++) {
        cin >> A[i] >> B[i];
        P[A[i]].push_back(B[i]);
        P[B[i]].push_back(A[i]);
    }

    int max = 0;
    int max_pos;
    minmax(1);
    for(int i = 1; i <= N; i++) {
        if(cnt[i] >= max) {
            max = cnt[i];
            max_pos = i;
        }
    }

    max = 0;
    minmax(max_pos);
    for(int i = 1; i <= N; i++) {
        if(cnt[i] >= max) {
            max = cnt[i];
            max_pos = i;
        }
    }

    cout << max + 1 << endl;
    return 0;
}