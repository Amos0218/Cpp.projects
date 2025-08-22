#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int m;
    cin >> m;
    vector<vector<int>> grid(m,vector<int>(m));
    for(int i=0; i <m; ++i){
        for(int j=0; i <m; ++j){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(m,vector<int>(m,0));
    dp[0][0] = grid[0][0];

    for(int i=1; i <m; ++i){
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }

    for(int i=1; i <m; ++i){
        dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j=1; j <m; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    cout << dp[m-1][m-1] << endl;
    return 0;
}