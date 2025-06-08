#include <iostream>
#include <string>
using namespace std;

int money ,eat_time, id;
int main(){
    cin >> money >> eat_time >> id;
    int n = eat_time;
    string food[2] = {"an Apple pie","a Corn soup"};
    
    while (true){
        if (money < 32){
            cout << "Wayne can't eat and drink.";
            break;
        }
        
        if (id == 0){
            money -= 32;
        }else{
            money -= 55;
        }
        cout << eat_time << ": " <<  "Wayne eats" << food[id] << ", " << "and now he has " << money << "dollars";
        eat_time += n;

    }


    return 0;
}