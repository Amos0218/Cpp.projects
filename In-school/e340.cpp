//差分

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> b(n);
    for(int i=0; i <n; ++i){
         cin >> b[i];
    }
    
    a[0] = b[0]; //初始第一項
    for(int i=1; i <n; ++i){  //從第二個（索引一）開始
         a[i] = b[i] - b[i-1];
    }
    for(int i=0; i <n; ++i){
         cout << a[i] << " ";
    }

    return 0;
}