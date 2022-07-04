#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{   
    int n;
    int i, j;
    int ii, jj;
    cin >> n;
    int i_a[n], i_b[n];
    int a[n][n];
    int max  = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if(max <= a[i][j]){
                max = a[i][j];
                i_a[0]= i;
                i_b[0] = j;
            }
        }
    }
    cout << max;
    max = 0;
    for(j = 1; j < n; j++){
        for(int l=-1; l <=1; l++){
            for(int m = -1; m <= 1; m++){
                ii = i_a[j-1] + l;
                jj = i_b[j-1] + m;
                if(ii == -1){
                    ii = n;
                }
                if(ii == n){
                    ii = 0;
                }
                if(jj == -1){
                    jj = n;
                }
                if(jj == n){
                    jj = 0;
                }
                int av = 0;

                for(i = 0; i < j; i++){
                    if(ii == i_a[i] && jj == i_b[i]){
                        av = 1;
                    }
                }
                if(ii == 0 && jj == 0){
                    av = 1;
                }
                //cout << "(" << ii << ")";
                if(av == 0){
                    if(max <= a[ii][jj]){
                        max = a[ii][jj];
                        //cout << " " << max << "("<< ii <<  " " << jj << ")" << "  ";
                        i_a[j] = ii;
                        i_b[j] = jj;
                    }
                }
                av =0;
            }
        }
        cout << max;
        max = 0;
    }
    return 0;
}