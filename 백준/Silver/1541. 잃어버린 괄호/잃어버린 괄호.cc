#include <bits/stdc++.h>

using namespace std;
string s;
int len, res, tmp;
bool flag;

int main(){
    cin >> s;
    len = (int)s.length();
    
    
    for(int i = 0 ; i <= len ; i++){
        if(s[i] == '-' || s[i] == '+' || i==len){
            if(flag){
                res-=tmp;
                tmp=0;
            }else {
                res+=tmp;
                tmp=0;
            }
            
            if(s[i]=='-') flag=true;
        }else{
            tmp*=10;
            tmp+= (s[i]-'0');
        }
    }
    
    cout << res << '\n';
    
    
}
