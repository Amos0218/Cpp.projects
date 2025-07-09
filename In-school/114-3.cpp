#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


bool isWords(char c) {
    return isalpha(c);
}

void reverseWords (string &s,int start, int end){
    int l = start,r = end-1;
    while (l<r){
        if (!isalpha(s[l])){
            l += 1;
        } else if (!isalpha(s[r])){
            r -= 1;
        } else{  //是字母
            swap(s[l],s[r]);
            l += 1;
            r -= 1;
        }
    }
}


int main(){
    string s;
    getline(cin,s);

    int words_count = 0;
    int n = s.size();
    int i =0;

    while(i < n){
        if(isWords(s[i])){
            int start = i;
            while(i <n && isWords(s[i]) ){
                i += 1;
            }
            int end = i;
            reverseWords(s,start,end);
            words_count += 1;
        } else{
            i += 1;
        }
    }
    cout << s << endl;
    cout << words_count << endl;

    
    return 0;
}