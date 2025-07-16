#include <iostream>
using namespace std;

int arr[100005] = {};  //大小看測資而定
int mer[100005] = {};

int solve(int arr[], int lb, int rb){
    if (lb + 1 == rb){
        return 0;
    }
    //拆分
    long long int ans = 0;
    int mid = lb + (rb - lb)/2;
    ans += solve(arr,lb,mid);
    ans += solve(arr,mid,rb);

    //合併
    int arr_lb = lb, arr2_lb = mid;
    int index = 0;

    while(arr_lb < mid && arr2_lb < rb){
        if (arr[arr_lb] < arr[arr2_lb]){  //左邊頭較小  
            mer[index] = arr[arr_lb]; 

            //算這一輪加多少能量
            long long int temp = arr[arr_lb];
            ans += temp * (rb - arr2_lb);  

            index += 1;
            arr_lb += 1;
        }else if (arr[arr_lb] >= arr[arr2_lb]){  //右邊頭較小 
            mer[index] = arr[arr2_lb];
            index += 1;
            arr2_lb += 1;
        }
    }
    // 再寫兩個while來處理還沒放進去的數字
    while(arr_lb < mid){
        mer[index] = arr[arr_lb]; 
        index += 1;
        arr_lb += 1;
    }
    while(arr2_lb < rb){
        mer[index] = arr[arr2_lb]; 
        index += 1;
        arr2_lb += 1;
    }
    // 把合併好的資料從mer塞回arr
    for(int i=lb; i < rb; ++i){
        arr[i] = mer[i - lb];
    }

    return ans%1000000007;

}

int main(){
    int n;
    cin >> n;
    for(int i=0; i <n; ++i){
        cin >> arr[i];
    }

    cout << solve(arr,0,n) << endl;

    return 0;
}