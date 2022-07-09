#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.141592653589793

int main()
{  
    long double a, b, d;
    //入力
    cin >> a >> b >> d;
    //出力
    cout << setprecision(100) << cos(d/180*PI) * a - sin(d/180*PI) * b << " " << setprecision(100) << sin(d/180*PI) * a + cos(d/180*PI) * b << endl;
    return 0;
}