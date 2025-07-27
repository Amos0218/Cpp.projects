#include <iostream>
#include <string>
using namespace std;

int pos[100000] = {};
int main(){

    string str;
    cin >> str;
    int len = str.length();
    int flag = 0; //判斷現在是當前單字的第幾個
    int index = 1; //現在是字串的第幾個字
    int group = 0; //有幾組答案

    for(int i=0; i <len; ++i){// 
        if (flag == 0 && (str[i] == 'T' || str[i] == 't')){
            flag = 1;
            pos[index] = i+1;
            index += 1;
        }else if (flag == 1 && (str[i] == 'Y' || str[i] == 'y')){
            flag = 2;
            pos[index] = i+1;
            index += 1;
        }else if (flag == 2 && (str[i] == 'S' || str[i] == 's')){
            flag = 3;
            pos[index] = i+1;
            index += 1;
        }else if (flag == 3 && (str[i] == 'H' || str[i] == 'h')){
            flag = 0;
            pos[index] = i+1;
            index += 1;
            group += 1;
        }
            
    }
        index -= 1; //把index減回來（因為每次判斷完都會加一）
        index -= index % 4; //把多餘的（還不完整的）扣掉
        
        cout << group << endl;
        for(int i=0; i <=index; ++i){
            if(i%4 == 0){
                cout << pos[i] << endl;
            }else{
                cout << pos[i] << " ";
            }
        }

    return 0;
}
