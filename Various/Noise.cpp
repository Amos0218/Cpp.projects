#include <iostream>
using namespace std;


int main() {
    string numbers;
    bool isPd = true;
    int n;
    cin >> numbers >> n;

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] - '0' == n) {
            numbers.erase(i, 1);  // 從第i個開始刪1的字元
            --i;  // 因為 erase 後，後面的字元往前移，i 要回退
        }
    }

    // 檢查是否為回文
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] != numbers[numbers.size() - 1 - i]) {
            isPd = false;
            break;
        }
    }

    if (!isPd) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}