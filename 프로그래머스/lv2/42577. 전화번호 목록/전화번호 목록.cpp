#include <bits/stdc++.h>

using namespace std;

map<string, bool> m;

bool solution(vector<string> phone_book) {
    
    for(auto phone_num : phone_book){ 
        string prefix = "";
        for(int j = 0 ; j < (int)phone_num.length()-1 ; j++){
            prefix+=phone_num[j];
            m[prefix]= true; // 모든 접두어를 저장해놓음.
        }
    }
    
    for(auto phone_num : phone_book) if(m[phone_num]) {return false;}
    
    return true;
}

// 다른 번호의 접두어인 경우 있으면 false
// 없으면 true 리턴