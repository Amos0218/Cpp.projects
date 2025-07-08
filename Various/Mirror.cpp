#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool isPd = true;  // 預設是回文
    string dictionary = "AHIMOTUVWXY";

    // 檢查每個字是否都在字典裡
    for (int i = 0; i < str.size(); ++i){
        bool in_dictionary = false;
        for (int j = 0; j < dictionary.size(); ++j){
            if (str[i] == dictionary[j]){
                in_dictionary = true;
                break;
            }
        }
        if (!in_dictionary){  // 若有一個不在字典裡，就報錯
            isPd = false;
            break;
        }
    }

    // 如果都在字典裡，才檢查是否為回文
    if (isPd){
        for (int i = 0; i < str.size(); ++i){
            if (str[i] != str[str.size() - 1 - i]){
                isPd = false;
                break;
            }
        }
    }

    if (isPd){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}