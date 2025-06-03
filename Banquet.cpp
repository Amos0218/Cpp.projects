#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str[200];

    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        if (str[i].size() > max_len) {
            max_len = str[i].size();  //先找出最長的字串的長度當作比較次數
        }
    }

    
    for (int i = 0; i < max_len; ++i) {
        for (int j = 0; j < n; ++j) {  
            if (str[j].size() <= i) {
                continue;
            }
            //  i是行、j是列 ，同時i代表字串
            if (isalpha(str[j][i])) {    
                cout << str[j][i];
            }
        }
    }

    return 0;
}