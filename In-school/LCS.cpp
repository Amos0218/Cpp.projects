#include <iostream>
#include <string>
using namespace std;


int dp[1005][1005] = {};
int main(){

    string str1,str2;
    while (cin >> str1 >> str2){
        int len1 = str1.length();
        int len2 = str2.length();

        for(int i=1; i <= len1; ++i){
            for(int j=1; j <= len2; ++j){
                if (str1[i-1] == str2[j-1]){   //因為索引從1開始，所以要減1
                    dp[i][j] = dp[i-1][j-1] + 1;  
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout << dp[len1][len2] << endl;

    }



}