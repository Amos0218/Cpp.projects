#include <iostream>
#include <vector>
using namespace std; 
long long ans = 0;

void dfs(int old){
    int n; 
    cin >> n;
    if (n == 0){
        return ;
    }
    if (old != 0){
        ans += abs(n-old);
    }
    if (n%2 == 1){
        dfs(n);
        dfs(n);
        dfs(n);
        
    }
}

int main(){
    dfs(0); //
    cout << ans;

    return 0;
}