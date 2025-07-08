#include <iostream>
#include <cctype>
using namespace std;

int main(){
   string data;
   getline(cin,data);
   
   int k;
   cin >> k;
   for (int i = 0;i < data.size(); ++i){
        if (isalpha(data[i]) && isupper(data[i])){
            data[i] = (data[i] - 'A' + k) % 26 + 'A';
        }
        else if (isalpha(data[i]) && islower(data[i])) {
            data[i] = (data[i] - 'a' + k) % 26 + 'a';
        }
   }
   cout << data << endl;

    return 0;
}