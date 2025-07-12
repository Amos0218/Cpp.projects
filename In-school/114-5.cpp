#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    int N, x, y;
    cin >> N >> x >> y;
    x--, y--; // change to 0-based

    vector<vector<int>> score(N, vector<int>(N));
    for(int i = 0; i< N; ++i){
        for(int j = 0; j< N; ++j){
            cin >> score[i][j];
        }
    }

    // 左上角為原點 (0,0)，(dx, dy, fx, fy, mx,my)
    vector<tuple<int, int, int, int, int, int>> moves = {
         {-1,  2,  0,  1,  0,  2}, // 1
        { 1,  2,  0,  1,  0,  2}, // 2
        { 2,  1,  1,  0,  2,  0}, // 3
        { 2, -1,  1,  0,  2,  0}, // 4
        { 1, -2,  0, -1,  0, -2}, // 5
        {-1, -2,  0, -1,  0, -2}, // 6
        {-2, -1, -1,  0, -2,  0}, // 7
        {-2,  1, -1,  0, -2,  0}  //8
    };

    vector<vector<int>> answer;  
    int max_total = -1000000;

    for(int i = 0; i < moves.size(); ++i){
        int dx, dy, s1x, s1y, s2x, s2y;
        tie(dx, dy, s1x, s1y, s2x, s2y) = moves[i];

        int first_x = x + s1x;
        int first_y = y + s1y;
        int second_x = x + s2x;
        int second_y = y + s2y;
        int end_x = x + dx;
        int end_y = y + dy;

        // 其中一步如果出界，跳過這輪
        if (first_x < 0 || first_x >= N || first_y < 0 || first_y >= N) continue;
        if (second_x < 0 || second_x >= N || second_y < 0 || second_y >= N) continue;
        if (end_x < 0 || end_x >= N || end_y < 0 || end_y >= N) continue;

        
        int a = score[first_x][first_y];     // first step 
        int b = score[second_x][second_y];   // second step
        int c = score[end_x][end_y];         // third step
        int total = a + b + c;

        answer.push_back({a, b, c, total});
        if (total > max_total){
            max_total = total;
        }
    }

    if (answer.empty()){
        cout << -1 << endl;
    } else {
        cout << answer.size() << endl;
        for(int i = 0 ; i < answer.size(); ++i){
            for(int j = 0; j < 4; ++j){
                cout << answer[i][j] << " " ;
            }
            cout << endl;
        }

        if (max_total < 0){
            cout << 0 << endl;
        }else{
            cout << max_total << endl;
        }
        
    }

    return 0;
}