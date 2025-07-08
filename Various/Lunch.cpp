#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    int r,c;
    cin >> r >> c;
    bool find = false;
    vector<vector<string>> food(r,vector<string> (c));

    for (int i=0; i<r; ++i){
        for(int j=0;j <c; ++j){
            cin >> food[i][j];
        }
    }
    string target;
    cin >> target;

    for (int i=0; i<r; ++i){
        for(int j=0;j <c; ++j){
            if (food[i][j] == target){
                cout << i+1 << " "<< j+1 << endl;
                find = true;
                }
        }
    }
    if (!find){
        cout << "0 0" ;
        return 0;
    }


    return 0;
}
