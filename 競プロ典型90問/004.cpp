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

    //行の合計値
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++){
            sum += A[i][j];
        }
        H_sum[i] = sum;
        sum = 0;
    }
    //列の合計値
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            sum1 += A[j][i];
        }
        W_sum[i] = sum1;
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