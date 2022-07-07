#include <iostream>
using namespace std;

    int sum = 0;
    int sum1 =0;
    int H, W;
    int A[2100][2100];
    int H_sum[2100], W_sum[2100];

int main()
{
    //入力
    cin >> H >> W;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++){
            cin >> A[i][j];
        }
    }

    //列,行合計値
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++){
            sum += A[i][j];
            sum1 += A[j][i];
        }
        H_sum[i] = sum;
        W_sum[i] = sum1;
        sum = 0;
        sum1 = 0;
    }
    
    //出力
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++){
            cout << H_sum[i] + W_sum[j] - A[i][j] << " ";
        }
        cout << endl;
    }
}