#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=1; i <= n; ++i){
        cin >> A[i];
    }
    vector<int> B(n);
    for(int i=1; i <= n; ++i){
        cin >> B[i];
    }
    int k1,k2;
    cin >> k1 >> k2 ;

    //
    bool A_win = true, B_win = true;
    for(int i = k1; i <= k2; ++i){
        if (A[i] < B[i]){
            A_win = false;
        }
        if (B[i] < A[i]){
            B_win = false;
        }
        if (B[i] == A[i]){
            A_win = false;
            B_win = false;
        }
    }
    if (A_win){
        cout << "A" << endl;
    }else if (B_win){
        cout << "B" << endl;
    }else{
        cout << "X" << endl;
    }


    return 0;
}