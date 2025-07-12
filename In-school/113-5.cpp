#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    string originalWord;
    cin >> originalWord;

    string lowerWord = originalWord;
    for (char &c : lowerWord) {
        c = tolower(c);  
    }

    int n = originalWord.length();
    vector<bool> used(n, false);
    vector<vector<int>> result;

    for(int i=0; i < n; ++i){
        if (lowerWord[i] == 't' && !used[i]){
            char target[4] = {'t','y','s','h'};
            vector<int> candidate;
            candidate.push_back(i);
            int current = i;

            bool valid = true;

            for(int k =1; k < 4; ++k){
                bool found = false;
                for(int j = current + 1; j< n; ++j){
                    if (lowerWord[j] == target[k] && !used[j]){
                        candidate.push_back(j);
                        current = j;
                        found = true;
                        break;
                    }
                }
                if (!found){
                    valid = false;
                    break;
                }
            }

            if (valid){
                vector<int> currentgroup;
                for(int idx : candidate){
                    currentgroup.push_back(idx + 1); // 輸出時是我們生活中的第幾個
                    used[idx] = true; // 標記原始位置
                }
                result.push_back(currentgroup);
            }
        }
    }

    // output
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}