#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long double x1,y1,z1,x2,y2,z2,x3,y3,z3;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    cin >> x3 >> y3 >> z3;
    long double value = fabs(x1*y2*z3 + x2*y3*z1 + x3*y1*z2 - x1*y3*z2 - x2*y1*z3 - x3*y2*z1) / 6;


    cout << fixed;    //固定小數點格式
    cout.precision(0);   //小數點後保留 0 位(也就是整數)
    cout << value << endl;

    return 0;
}