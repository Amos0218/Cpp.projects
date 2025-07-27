// 裝貨櫃問題

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_CAPACITY = 100;

int main() {
    int N;
    while (cin >> N) {
        vector<int> volume(N), profit(N);
        for (int i = 0; i < N; ++i) {
            cin >> volume[i] >> profit[i];
        }

        // 初始化 dp[0 ~ 100] = 0
        vector<int> dp(MAX_CAPACITY + 1, 0);

        // 0/1 背包（由後往前）
        for (int i = 0; i < N; ++i) {
            for (int j = MAX_CAPACITY; j >= volume[i]; --j) {
                dp[j] = max(dp[j], dp[j - volume[i]] + profit[i]);
            }
        }

        int maxProfit = *max_element(dp.begin(), dp.end());
        cout << maxProfit << endl;
    }

    return 0;
}