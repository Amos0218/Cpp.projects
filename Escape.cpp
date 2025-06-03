#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;

    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    char map[101][101];
    memset(map, '.', sizeof(map));  //初始化所有格子為.

    string str;
    cin >> str;

    int x = 0, y = 0, d = 0;
    map[x][y] = '*';

    for (int i = 0; i < str.size(); ++i){
        int move_cnt = str[i] - '0';  //取得當前移動次數
        for (int j = 0; j < move_cnt; ++j){
            x += dir[d][0];
            y += dir[d][1];

            if (x < 0 || x >= r) x -= dir[d][0];
            if (y < 0 || y >= c) y -= dir[d][1];

            map[x][y] = '*';
        }
        d = (d + 1) % 4;  //取得下一個方向（右下左上）
    }

    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}