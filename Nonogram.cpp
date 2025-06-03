#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n=0;
    cin >> n;
    vector<vector<int>> flag (n,vector<int>(n));
    for (int i = 0;i < n; ++i){
        for (int j = 0;j <n;++j){
            cin >> flag[i][j];
        }
    }
    int a1[5],a2[5]; //存答案
    for (int j = 0;j < n; ++j){
        int count = 0;
        for (int i = 0;i < n;++i){
            if (flag[i][j] == 1){
                count += 1;
            }
        }
        a1[j] = count;
    }

    return 0;
}