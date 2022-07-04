#include <iostream>
#include <string.h>
using namespace std;

    long long N, Q;
    string s1;
    char s[1 << 20];
    long long qt[1 << 20];
    long long qx[1 << 20];
    long long pos = 0;

void q1(long long qx) 
{
    int pri_pos;
    pri_pos = pos + qx - 1;
    if(pos + qx - 1 >= N) {
        pri_pos = pos + qx - 1 - N; 
    }
    cout << s[pri_pos] << endl;
}

void q2(long long qx)
{
    //時間内 O(1)
    pos = pos - qx;
    if(pos < 0) {
        pos = N + pos;
    }
    //時間超過 O(Q)
    /*for(int i = 0; i < qx; i++){
        pos--;
        if(pos == -1) {
        pos = N - 1;
        }
    }*/
}

int main()
{
    //入力
    cin >> N >> Q >> s1;
    for(int i = 0; i < Q; i++) {
        cin >> qt[i] >> qx[i];
    }
    for(int i = 0; i < N; i++) {
        s[i] = s1[i];
    }

    for(int i = 0; i < Q; i++) {
        if(qt[i] == 2) q1(qx[i]);
        else q2(qx[i]);
    }
    return 0;
}