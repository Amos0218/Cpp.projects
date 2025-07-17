#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int x1, y1, z1;
    long long int x2, y2, z2;
    long long int x3, y3, z3;

    // 輸入三個點的座標
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    cin >> x3 >> y3 >> z3;

    // 計算體積的公式
    long long int value = fabs(
        x1 * y2 * z3 + x2 * y3 * z1 + x3 * y1 * z2
      - x1 * y3 * z2 - x2 * y1 * z3 - x3 * y2 * z1
    ) / 6;

    // 設定輸出格式為整數
    cout << value << endl;

    return 0;
}