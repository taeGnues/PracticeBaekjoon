#include <bits/stdc++.h>

using namespace std;

int dp[10001], t;

int main(){
    
    
    dp[0] = 1;
    
    for(int i = 1; i <= 3 ; i++){
        for(int j = 1 ; j < 10001 ; j++){
            if(j-i>=0) dp[j] += dp[j-i];
        }
        
        
    }
    
    cin >> t;
    while(t--){
        int n=0;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    
    
    
}
