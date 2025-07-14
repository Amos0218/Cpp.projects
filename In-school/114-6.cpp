#include <iostream>
using namespace std;

int main(){
    int sb ,bp,n,ta;
    cin >> sb >>bp >> n >> ta;
    int base_energy = 3, bonus_energy = 0;
    int hit_rate;

    hit_rate = n/(sb*ta) * 100;
    if (hit_rate >= 80 && hit_rate <= 100){
        bonus_energy = 2;
    }else if (hit_rate >= 40 && hit_rate <= 80){
        bonus_energy = 1;
    }

    int ans = base_energy + (n/sb*bp) + bonus_energy;

    if (ans > 100){
        ans = 100;
    }

    cout << ans << "%" <<  endl;
    return 0;
}