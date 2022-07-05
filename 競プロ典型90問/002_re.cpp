#include <iostream>
#include <math.h>
using namespace std;

long long N;
long long a[1 << 21];

void desc(void)
{
    bool b = true;
    long long cnt_0 = 0, cnt_1 = 0;

    for(int i = 0; i < N; i++) {
        if(a[i] == 0) cnt_0++;
        else cnt_1++;

        if(cnt_0 < cnt_1) b = false;
    }
    if(cnt_0 == cnt_1 && b == true) {
        for(int i = 0; i < N; i++) {
            if(a[i] == 0) cout << "(";
            else cout << ")";
        }
        cout << endl;
    }
}
int main()
{
    long long a1;
    //入力
    cin >> N;
    
    for(int i = 0; i < pow(2,N); i++) {
        a1 = i;
        for(int j = 0; j < N; j++){
            a[N - j - 1] = a1 >> (N - j - 1);
            a1 = a1 - ((a1 >> (N - j - 1)) << (N - j -1));
        }
        desc();
    }
}