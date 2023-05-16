#include <bits/stdc++.h>

using namespace std;

string S, bS, ret;
stack<char> s;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S >> bS;
    
    for(auto i : S){
        s.push(i);
        
        if(s.size() >= bS.size() && s.top() == bS[bS.size()-1]){
            string tmp = "";
            for(char l : bS){
                tmp += s.top();
                s.pop();
            }
            
            reverse(tmp.begin(), tmp.end());
            
            if(bS!=tmp){
                for(auto k : tmp){
                    s.push(k);
                }
            }
        }
        
        
    }
    
    if(s.size()){
        while(s.size()){
            ret += s.top();
            s.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    } else{
        cout << "FRULA" << '\n';
    }
}
