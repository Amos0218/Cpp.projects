#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while (n--){       // 重複執行 n 次，每次處理一組輸入的字串」
        int count = 0;
        stack <int> stk;
        cin >> s;
        for(int i=0; i < s.length(); ++i){
            if(!stk.empty() && stk.top() == '(' && s[i] == ')'){
                stk.pop();
                count += 1;
            }else{
                stk.push(s[i]);
            }
        }
        if(!stk.empty()){
            count =0;
        }
        cout << count << endl;
    
    }
    

    return 0;
}
