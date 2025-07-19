#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<char>> grid(8, vector<char>(8, '.')); 

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            int a;
            cin >> a;
            if (a == 1){
                grid[i][j] = 'O'; // black
            } else if (a == 2){
                grid[i][j] = '@'; // white
            }
        }
    }

    int x, y, p;
    cin >> x >> y >> p;
    x -= 1;
    y -= 1;


    //決定我方、敵方旗子
    char self = (p == 1 ? 'O' : '@');       
    char enemy = (p == 1 ? '@' : 'O');      
    grid[x][y] = self;            // 下棋

    int dir[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        { 0,-1},        {0,1},
        { 1,-1},{1,0},{1,1}
    };

    for (int d = 0; d < 8; ++d){
        int dx = dir[d][0];
        int dy = dir[d][1];
        int cx = x + dx;
        int cy = y + dy;
        vector<pair<int,int>> path;   //用來暫存碰到的敵方棋子座標

        // 走到底，找敵方連線
        while (cx >= 0 && cx < 8 && cy >= 0 && cy < 8 && grid[cx][cy] == enemy){ //找到敵人的話
            path.push_back({cx, cy});  
            //沿著原方向繼續搜尋
            cx += dx;
            cy += dy;
        }

        // 若遇到我方
        if (cx >= 0 && cx < 8 && cy >= 0 && cy < 8 && grid[cx][cy] == self) {
            for (pair<int, int> pos : path) {  //把中間所有enemy換成自己的棋子
                int px = pos.first;
                int py = pos.second;
                grid[px][py] = self;
            }
        }
    }

    
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}