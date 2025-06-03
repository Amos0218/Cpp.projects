#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> s(n);
    for (int i = 0;i < n;++i){
        cin >> s[i];
    }
    int r,c;
    cin >> r >> c;
    vector<vector<int>> goods(r,vector<int>(c));
    for (int i = 0;i < r;++i){
        for (int j = 0;j < c;++j){
            cin >> goods[i][j];
        }
    }
    for (int i = 0;i < n ; ++i){
        bool is_find = false;
        int x = 0,y = 0;
        for (int a = 0;a < r; ++a){
            for (int b = 0; b < c; ++b){
                if (goods[a][b] == s[i]){
                    x = a;
                    y = b;
                    is_find = true;
                    break;
                }
            }
        }
        if (!is_find){
            cout <<  -1 << endl;
        }else{
            cout << x+1 << " " << y+1 << endl;
        }

    }
    return 0;
}