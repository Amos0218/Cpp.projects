// dfs範例


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int r,c;
int ans = 0;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //上下左右
void dfs(vector<vector<int>> &mp,vector<vector<int>> &visited,int x, int y){
    // 1. 看一個點有沒有被看過，如果有就回傳到上一層
    if (visited[x][y] == 2){
        return ;
    }

    //否則標記這個點為看過
    visited[x][y] = 2;

    // 2. 找他的鄰居
    for(int i=0; i <4; ++i){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        // if ’在範圍內‘ 且 ’mp[nx][ny]是0‘ 且 ‘沒有被拜訪過’
        if (nx >= 0 && nx < r && ny >= 0 && nx < c && mp[x][y] == mp[nx][ny] && visited[nx][ny] == 0){
            ans += 1;
            dfs(mp,visited,nx,ny);
        }
    }
}



int main(){
    int t;
    cin >> t;
    int x,y;
    //input (因為這題的輸入之間沒有空格隔開，所以用string的方式寫)
    for(int i=0; i <t; ++i){
        r=0;
        vector<vector<int>> mp(101,vector<int>(101,0));
        vector<vector<int>> visited(101,vector<int>(101,0)); //判斷某點是否已拜訪
        cin >> x >> y;
        cin.ignore(); //把上面的'\n'吃掉
        string s;  
        while(getline(cin,s)){    // read each line
            if(s.size() == 0){     //read space
                break;   
            }
            c = s.length();
            for(int j=0; j < c; ++j){
                mp[r][j] = s[j] - '0';  //扣掉跟文字0的距離就可以獲得整數
                if (mp[r][j] == 1){  // is land
                    visited[r][j] = 2;
                } 
            }
            r += 1;
        }
        dfs(mp,visited,x-1,y-1); // 1.graph(2d) 2.visited(2d) 3. x 4. y
        cout << ans + 1 << endl;
        // 初始化下一輪
        ans = 0; 
        r = 0;
        c = 0;  
    }


    return 0;
}