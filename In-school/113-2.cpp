#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,count = 0;
    cin >> n;
    vector<int> bath(n);
    for (int i=0; i<n; ++i){
        cin >> bath[i];
    }

    for(int i=0; i<n; ++i){
        if (i == 0 && bath[0] == 0 && bath[1] == 0 ){
            count += 1;
        }
        else if (i == n-1 && bath[n-1] == 0 && bath[n-2] == 0 ){
            count += 1;
        }
        else if (bath[i] == 0  && bath[i-1] == 0 && bath[i+1] == 0){
            count += 1;
        }
    }

    cout << count << endl;
    return 0;

}
    