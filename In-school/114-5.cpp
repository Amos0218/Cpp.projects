#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
bool isValid(int x , int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}



int main(){
    int x, y;
    cin >> N >> x >> y;
    x--, y--; // change to 0-based

    // 前面是列，後面是行
    int dir[8][6] = {
        {-1,0,-2,0,-2,1},
        {0,1,0,2,-1,2},   
        {0,1,0,2,1,2},
        {1,0,2,0,2,1},
        {1,0,2,0,2,-1},
        {0,-1,0,-2,1,-2},
        {0,-1,0,-2-1,-2},
        {-1,0,-2,0,-2,-1}
    };

    int ans[8][4] = {};  //存可能的答案
    int index = 0;
    int mx = 0;

    vector<vector<int>> score(N, vector<int>(N));
    for(int i = 0; i< N; ++i){
        for(int j = 0; j< N; ++j){
            cin >> score[i][j];
        }
    }

    for(int i = 0; i< N; ++i){
        for(int j = 0; j< N; ++j){
            if (i == x && j == y){
                for(int k=0; k <8; ++k){
                    int nx = x + dir[k][0],ny = y + dir[k][1];
                    int nx1 = x + dir[k][2],ny1 = y + dir[k][3];
                    int nx2 = x + dir[k][4],ny2 = y + dir[k][5];
                    if (isValid(nx,ny) && isValid(nx1,ny1) && isValid(nx2,ny2)){
                        ans[index][0] = score[nx][ny];
                        ans[index][1] = score[nx1][ny1];
                        ans[index][2] = score[nx2][ny2];
                        ans[index][3] = score[nx][ny] + score[nx1][ny1] + score[nx2][ny2];
                        if (ans[index][3] > mx){
                            mx = ans[index][3];
                        }
                        index += 1;
                    }
                }    
            }
        }
    }
    
    if (index  == 0){
        cout << -1 << endl;
    }else{
        cout << index << endl;
        for (int i=0; i <index ; ++ i){
            cout << ans[i][0] <<" " << ans[i][1] <<" "<< ans[i][2] <<" "<< ans[i][3]  << endl; 
        }
        cout << mx << endl;
    }
    return 0;
} 