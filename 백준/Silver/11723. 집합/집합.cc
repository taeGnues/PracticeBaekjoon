#include <bits/stdc++.h>

using namespace std;

int M, S;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M;
    for(int i = 0 ; i < M ; i++){
        string tmp;
        int idx;
        
        cin >> tmp;
        
        if(tmp == "add"){
            cin >> idx;
            idx = idx - 1;
            S |= (1<<idx); // idx번째 bit on
        }else if(tmp == "remove"){
            cin >> idx;
            idx = idx - 1;
            S &= ~(1<<idx); // idx 번째 bit off
        }else if(tmp == "check"){
            cin >> idx;
            idx = idx - 1;
            if(S & (1<<idx)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }else if(tmp == "toggle"){
            cin >> idx;
            idx = idx - 1;
            if((S & (1<<idx))){ // idx번째가 켜져있다면 끄기
                S &= ~(1<<idx);
            } else{ // 꺼져있다면 키기.
                S |= (1<<idx);
            }
        }else if(tmp=="all"){
            S = 0xFFFFF;
        }else if(tmp=="empty"){
            S = 0;
        }
    }
    
    
    
    
    
}
