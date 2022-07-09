#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string S, T;
    string s1[1 << 17], t1[1 << 17];
    //入力
    cin >> S >> T;

    int cnt_s = 0;
    s1[0].push_back(S[0]);
    for(int i = 1; i < S.length(); i++) {
        if(S[i] == S[i-1]) {
            s1[cnt_s].push_back(S[i]);
        } else {
            cnt_s++;
            s1[cnt_s].push_back(S[i]);
        }
    }
    int cnt_t = 0;
    t1[0].push_back(T[0]);
    for(int i = 1; i < T.length(); i++) {
        if(T[i] == T[i-1]) {
            t1[cnt_t].push_back(T[i]);
        } else {
            cnt_t++;
            t1[cnt_t].push_back(T[i]);
        }
    }
    if(cnt_s == cnt_t){
        for(int i = 0; i < cnt_s + 1; i++) {
            if(s1[i] == t1[i]) {
                if(i ==  cnt_s) cout << "Yes" << endl;
            } else {
                if(s1[i].length() > 1 && t1[i].length() > 1) {
                    if(i ==  cnt_s) cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                    break;
                }
            }
        }
    }else {
        cout << "No" << endl;
    }
    return 0;
}