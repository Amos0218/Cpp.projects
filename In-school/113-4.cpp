#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> student;
    int x;
    while(cin >> x && x != -1){
        student.push_back(x);
    }
    int n; // 班級人數
    cin >> n;

    vector<int> count(n+1 ,0);    // 記錄每個座號被填幾次
    int correct_count = 0;

    for (int num : student){
        if (num >= 1 && num <= n ){
            count[num] += 1;
            correct_count += 1;
        }
    }
    
    bool allabsent = true;
    for(int i=1; i<=n; ++i){
        if (count[i] > 0){
            allabsent = false;
            break;
        }
    }

    if(allabsent){
        cout << "really" << endl;
        return 0; // 如果是really的話就直接終止

    }else {      //不是全部缺席
        bool allpresent = true;
        for(int i=1; i<=n; ++i){
            if(count[i] == 0){  //缺席的人
                cout << i << " " ;
                allpresent = false;
            }
        }
        if (allpresent){
            cout << "p" << endl;
        }

    }

    //重複次數
    int repeat = 0;
    for(int i=1; i<=n; ++i){
        if(count[i] > 1){
            repeat += count[i] - 1;
        }
    }
    cout << endl;
    cout << repeat << endl;

    if(correct_count == n){
        cout << "pass" << endl;
    }else{
        cout << "fail" << endl;
    }

    return 0;
}