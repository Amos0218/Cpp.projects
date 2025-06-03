#include <iostream>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int time_A[100][2];
    int time_B[100][2];
   
    for (int i = 0; i < N; ++i){
        cin >> time_A[i][0] >> time_A[i][1];
    }
    for (int i = 0; i < N; ++i){
        cin >> time_B[i][0] >> time_B[i][1];
    }
    int D;
    cin >> D;

    int id1 = 0,id2 = 0;
    int ans_s = -1,ans_e = -1;
    while(id1 < N && id2 < M ){
        int start = max(time_A[id1][0],time_B[id2][0]);
        int end = max(time_A[id1][1],time_B[id2][1]);

        if (end - start >= D){
            ans_s = start;
            ans_e = end;
            break;
        }
        if (time_A[id1][1] > time_B[id2][1]){
            id1 += 1;
        }else{
            id2 += 1;
        }
    }
    if (ans_s == -1){
        cout << -1 << endl;
    }else{
        cout << ans_s << " " << ans_e << endl;
    }



    return 0;
}
