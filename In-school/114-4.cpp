#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,t,k;
    cin >> n >> t >> k;

    priority_queue<int> pq;
    for (int i=0; i <n; ++i){
        int p;
        cin >> p;
        if (p >0){
            pq.push(p);
        }
    }

    int total = 0;
    while (t-- && !pq.empty()){     //如果 t > 0，會回傳 true，然後再做 t = t - 1
        int top = pq.top();
        pq.pop();
        total += top;
        int next = top - k; //下一次可以增加的飽足感
        if (next > 0){
            pq.push(next);
        }
    }

    cout << total << endl;



    return 0;
}