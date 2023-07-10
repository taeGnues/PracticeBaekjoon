#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    ios::sync_with_stdio(false);

    getline(cin, s); // 개행문자 포함한 문자열 받기
    
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]=='<'){
            for(;i < s.size();i++){
                cout << s[i];
                if(s[i]=='>') break;
            }
        } // 태그는 그대로 출력
        else {
            vector<char> v;
            for(;i < s.size();i++){
                if(s[i]==' ' || s[i]=='<') break;
                v.push_back(s[i]);
            }
           
            reverse(v.begin(), v.end()); // 문자열 뒤집기
            for(auto k : v) cout << k;
            if(s[i]==' ') cout << ' ';
            else if(s[i]=='<') i--;
        }
    }
    cout << '\n';


}
