#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    int w,h,n,count = 0;
    cin >> w >> h;
    cin >> n;
    vector<vector<char>> grid(w, vector<char>(h));
    vector<pair<char, pair<int, int>>> letters;

    for (int i = 0;i < w;++i){
        for (int j = 0;j < h; ++j){
            cin >> grid[i][j];
            if (isalpha(grid[i][j])){
                letters.push_back({grid[i][j], {i,j}});
                count += 1;
            }
        }
    }
    if (count != n){
        cout << "Mission fail." << endl;
    }else{
        sort(letters.begin(), letters.end()); //按照先後排
        for (int i = 0; i < n && i < letters.size(); ++i) {
            cout << letters[i].second.first << " "<< letters[i].second.second << endl;
        }
    }
    return 0;
}


//測試