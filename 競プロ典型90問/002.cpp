#include <iostream>
#include <math.h>
using namespace std;

long long n;
long long a[20];

bool desc (void)
{   
    long long count_0 = 0, count_1 = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == 0) count_0++;
        else count_1++;
        if(count_0 > count_1) {
            return false;
            break;
        }
    }
    if(count_0 == count_1) return true;
    else return false;
}

int main()
{   
    //入力
    long long s;
    cin >> n;

    for(int i = 0; i < pow(2, n); i++) {
        for(int j = 0; j < n; j++) {
            s = (i >> (n-j)) << (n-j);
            a[n-j-1] = (i-s) >> (n-j-1);
        }

        if(desc() == true) {
            for(int k = 0; k < n; k++){
                if(a[k] == 1) cout << "(";
                else cout << ")";
            }
            cout << endl;
        }
    }
}