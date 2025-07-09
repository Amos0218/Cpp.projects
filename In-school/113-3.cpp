#include <iostream>
using namespace std;

int main(){
    int a,b,cnt = 0;
    cin >> a >> b;
    for(int i=a; i<b+1; ++i){
        if (i % 11 == 0 || i == 0){
            cnt += 1;
        }
    }
    cout << cnt << endl;

    return 0;
    //666
}