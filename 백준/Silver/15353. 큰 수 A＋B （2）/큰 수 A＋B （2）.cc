#include <bits/stdc++.h>

using namespace std;
string A, B;
string total="";
int mx, mn;

void go(int here, int carry){
    if(here == -1) {
        if(carry) total = to_string(carry) + total;
        
        return;
        
    }
    
    int res = (A[here]-'0') + (B[here]-'0') + carry;
    
    if(res >= 10) {
        total = to_string(res-10) + total;
        go(here-1, res/10);
    } else{
        total = to_string(res) + total;
        go(here-1, 0);
    }

    
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    mx = max((int)A.length(), (int)B.length());
    mn = min((int)A.length(), (int)B.length());
    
    if((int)A.length()!=(int)B.length()){
       
        
        if((int)A.length() > (int)B.length()){
            for(int i = 0 ; i < mx-mn ; i++){
                B = "0" + B;
            }
        }else if((int)A.length() < (int)B.length()){
            for(int i = 0 ; i < mx-mn ; i++){
                A = "0" + A;
            }
        }
    }
    
    go(mx-1,0);
    
    cout << total;
    
    
}
