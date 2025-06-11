#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int count_S = 0,count_H = 0,count_D = 0, count_C = 0,max = 0;
    vector<string> cards ;

    for (int i=0; i<13; ++i){
        string card;
        cin >> card;
        cards.push_back(card);
    }

    for (string card : cards){
        char flower = card[0];
        if (flower == 'S'){
            count_S += 1;
        }else if (flower == 'H'){
            count_H += 1;
        }else if (flower == 'D'){
            count_D += 1;
        }else if (flower == 'C'){
            count_C += 1;
        }
    }
    for (string card : cards){
        string number = card.substr(1);
        if (number == "A"){
            max += 4;
        }else if (number == "K"){
            max += 3;
        }else if (number == "Q"){
            max += 2;
        }else if (number == "J"){
            max += 1;
        }

    }
    cout << count_S << " " << count_H << " "<< count_D << " "<< count_C << endl;
    cout << max << endl;







    



    return 0;
}