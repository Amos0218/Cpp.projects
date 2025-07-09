#include <iostream>
using namespace std;

int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int count = 0;
    for(int i=1; i<=n; ++i){
        if (i%a == 0 || i%b == 0 || i%c == 0){
            count += 1;
        }
    }
    cout << count ;



    return 0;
}