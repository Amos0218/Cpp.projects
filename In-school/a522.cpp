#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> rods(p);
        for (int i = 0; i < p; ++i) {
            cin >> rods[i];
        }

        vector<bool> dp(n + 1, false);  // dp[i] = 是否可以湊出長度 i
        dp[0] = true; // 初始狀態：不選任何金屬棒就能湊出 0

        for (int i = 0; i < p; ++i) {
            int len = rods[i];
            // 從 n 到 len（倒序）來避免重複使用一根棒子
            for (int j = n; j >= len; --j) {
                if (dp[j - len]) {
                    dp[j] = true;
                }
            }
        }

        if (dp[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}