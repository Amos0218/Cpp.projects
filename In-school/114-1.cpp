#include <iostream>
using namespace std;

long long int gcd(long long a, long long b){
    if (b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    long long int n,a,b,c;
    cin >> n >> a >> b >> c;

    long long int ab = a/gcd(a,b)*b;  // 如果先乘b會太大
    long long int bc = b/gcd(b,c)*c;
    long long int ac = a/gcd(a,c)*c;
    long long int abc = ab/gcd(ab,c)*c;

    long long int ans = n/a + n/b + n/c - n/ab - n/bc - n/ac + n/abc;

    cout << ans << endl;
    


    return 0;
}