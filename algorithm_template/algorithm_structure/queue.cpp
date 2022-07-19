#include <iostream>
#include <queue>
using namespace std;

long long N, q;
long long p[1 << 17];
long long t = 0;
queue <long long> Q;
queue <long long> Q_num;

int main()
{
    //入力
    cin >> N >> q;
    for(int i = 1; i <= N; i++) {
        cin >> p[i];
        Q.push(p[i]);
        Q_num.push(i);
    }

    while(!Q.empty()) {
        if(Q.front() > q) {
            Q.push(Q.front() - q);
            Q.pop();
            t += q;
            Q_num.push(Q_num.front());
            Q_num.pop();
        } else {
            t += Q.front();
            cout << Q_num.front() << " " << t << endl;
            Q_num.pop();
            Q.pop();
        }
    }
}