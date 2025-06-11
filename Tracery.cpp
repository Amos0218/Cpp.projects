#include <iostream>
#include <vector>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

  
    vector<vector<int>> left_right(h, vector<int>(2 * w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            left_right[i][j] = grid[i][j];  //left           
            left_right[i][2 * w - 1 - j] = grid[i][j]; //right      
        }
    }


    vector<vector<int>> up_down(2 * h, vector<int>(2 * w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < 2 * w; ++j) {
            up_down[i][j] = left_right[i][j];    //up       
            up_down[2 * h - 1 - i][j] = left_right[i][j];   //down 
        }
    }

 
    for (int i = 0; i < 2 * h; ++i) {
        for (int j = 0; j < 2 * w; ++j) {
            cout << up_down[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}