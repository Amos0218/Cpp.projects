//低地距離

#include <iostream>
#include <vector>

using namespace std;

long long int sol(vector<int> &arr,vector<int> &checked,int lb, int rb){
    if (lb == rb){
        return 0;
    }    
    int mid = lb + (rb-lb)/2;
    //暫存小數字跟大數字（成雙成對所以乘以二，大數字個數不用再加一）
    vector<int> small,large;  
    small.resize((mid-lb+1)*2);
    large.resize((rb-mid)*2);
    long long int ans = 0;
    int small_index = 0,large_index = 0,cnt = 0;
    for(int i=0; i < (rb-lb + 1)*2 ; ++i){
        //如果是小數字
        if (arr[i] <= mid){
            small[small_index] = arr[i];
            small_index += 1;
            //更新答案
            ans += cnt;
        }else{ //是大數字
            large[large_index] = arr[i];
            large_index += 1;
            // 如果大數字還沒被算過,cnt += 1
            if (checked[arr[i]] == 0){
                cnt += 1;
                checked[arr[i]] = 1;
            }else{// 如果大數字還沒被算過,cnt -= 1
                cnt -= 1;
                checked[arr[i]] = 0;
            }
        }   
    }

    ans += sol(small,checked,lb,mid); //呼叫小數字陣列得到的答案
    ans += sol(large,checked,mid+1,rb); //呼叫大數字陣列得到的答案

    return ans;
}



int main(){
    long long int n;
    cin >> n;
    vector<int> arr(200005);
    for(int i=0; i < 2*n; ++i){
        cin >> arr[i];
    }
    vector<int> checked(100005);  //確認數字有沒有被算過
    cout << sol(arr,checked,1,n);

    return 0;
}

 