#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int dp[50][10000] = {};

    for (int i = 0; i < m; ++i) {
        int a[10000] = {}, l[10000] = {}, r[10000] = {};
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        // 取從左到右跟從下面下來的最大值
        for (int j = 0; j < n; ++j) {
            if (i == 0) {
                if (j == 0) l[j] = a[j];
                else l[j] = l[j-1] + a[j];
            } else {
                if (j == 0) l[j] = dp[i-1][j] + a[j];
                else l[j] = max(dp[i-1][j], l[j-1]) + a[j];
            }
        }

        // 取從右到左跟從上面下來的最大值
        for (int j = n-1; j >= 0; --j) {
            if (i == 0) {
                if (j == n-1) r[j] = a[j];
                else r[j] = r[j+1] + a[j];
            } else {
                if (j == n-1) r[j] = dp[i-1][j] + a[j];
                else r[j] = max(dp[i-1][j], r[j+1]) + a[j];
            }
        }

        // 合併左右最大值
        for (int j = 0; j < n; ++j) {
            dp[i][j] = max(l[j], r[j]);
        }
    }

    // 找出最後一排最大值
    int ans = dp[m-1][0];
    for (int j = 1; j < n; ++j) {
        ans = max(ans, dp[m-1][j]);
    }

    cout << ans << endl;
    return 0;
}