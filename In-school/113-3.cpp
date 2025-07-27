#include <iostream>
using namespace std;

int main(){
    long long int a,b,cnt = 0;
    cin >> a >> b;
    cnt = b / 11 - (a - 1) / 11;
    if (a<=0 && b >= 0){
        cnt += 1;
    }

    cout << cnt << endl;

    return 0;
}