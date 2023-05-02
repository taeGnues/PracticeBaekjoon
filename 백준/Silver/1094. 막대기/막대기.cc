#include <bits/stdc++.h>

using namespace std;

int X;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> X;
    int ret=0;
    while (X>0){
        if(X%2){
            ret++;
        }
        
        X=X/2;
    }
        
    cout << ret;
    
    
}
