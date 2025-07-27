

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int N,X;
    cin >> N >> X;
    vector<int> volume(N), profit(N);
        for (int i = 0; i < N; ++i) {
            cin >> volume[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> profit[i];
        }

        vector<int> dp(X + 1, 0);

        // 0/1 背包（由後往前）
        for (int i = 0; i < N; ++i) {
            for (int j = X; j >= volume[i]; --j) {
                dp[j] = max(dp[j], dp[j - volume[i]] + profit[i]);
            }
        }

        cout << dp[X] << endl;
    

    return 0;
}