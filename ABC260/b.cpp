#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int N, X, Y, Z;
int A[1001], B[1001], SUM[1001];
int num1[1001];
int ans[1001];

void d(int n)
{
    for(int i = n; i <= N - 1; i++) {
        A[i] = A[i+1];
        B[i] = B[i+1];
        SUM[i] = SUM[i+1];
        num1[i] = num1[i+1];
    }
}

void d2(int n, int c)
{
    for(int i = n; i < c; i++) {
       ans[i] = ans[i + 1];
    }
}

int main()
{
    //入力
    cin >> N >> X >> Y >> Z;

    for(int i = 1; i <= N; i++)  {
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++)  {
        cin >> B[i];
    }
    for(int i = 1; i <= N; i++)  {
        SUM[i] = A[i] + B[i];
    }
    for(int i = 1; i <= N; i++)  {
        num1[i] = i;
    }

    int cnt = 0;
    int num;
    for(int i = 1; i <= X; i++)  {
        int max = -1;
        for(int j = 1; j <= N - i + 1; j++) {
            if(max < A[j]) {
                max = A[j];
                num = j;
            }
        }
        ans[cnt] = num1[num];
        cnt++;
        max = -1;
        d(num);
    }

    for(int i = 1; i <= Y; i++)  {
        int max = -1;
        for(int j = 1; j <= N - i - X + 1; j++) {
            if(max < B[j]) {
                max = B[j];
                num = j;
            }
        }
        ans[cnt] = num1[num];
        cnt++;
        max = -1;
        d(num);
    }

    for(int i = 1; i <= Z; i++)  {
        int max = -1;
        for(int j = 1; j <= N - i - X - Y + 1; j++) {
            if(max < SUM[j]) {
                max = SUM[j];
                num = j;
            }
        }
        ans[cnt] = num1[num];
        cnt++;
        max = -1;
        d(num);
    }
    
    //出力
    int min = 1000;
    int k;
    for(int j = 0; j < cnt; j++) {
         for(int i = 0; i < cnt-j; i++) {
            if(min > ans[i]) {
                min =  ans[i];
                k = i;
            }
        }
        cout << min << " ";
        min = 1000;
        d2(k, cnt - j);
    }
    cout << endl;
    return 0;
}
