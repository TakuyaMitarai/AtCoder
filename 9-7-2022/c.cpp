#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string S, T;
    vector<string> s1, t1;
    s1.resize(1 << 18);
    t1.resize(1 << 18);
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
    int s1_size = cnt_s + 1, t1_size = cnt_t + 1;
    if(s1_size == t1_size){
        for(int i = 0; i < s1_size; i++) {
            if(s1[i][0] == t1[i][0]) {
                if((s1[i].length() > 1 && t1[i].length() >= s1[i].length()) || (s1[i].length() == 1 && t1[i].length() == 1)){
                    if(i ==  s1_size - 1) cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                    break;
                }
            } else {
                cout << "No" << endl;
                break;
            }
        }
    }else {
        cout << "No" << endl;
    }
    return 0;
}