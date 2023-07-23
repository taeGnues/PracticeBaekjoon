#include <bits/stdc++.h>

using namespace std;

map<string, bool> m;

bool solution(vector<string> phone_book) {
    
    for(auto i : phone_book){
        string a = "";
        for(int j = 0 ; j < (int)i.length()-1 ; j++){
            a+=i[j];
            m[a]= true; // 모든 접두어를 저장해놓음.
        }
    }
    
    for(auto i : phone_book) if(m[i]) {return false;}
    
    return true;
}

// 다른 번호의 접두어인 경우 있으면 false
// 없으면 true 리턴