#include <bits/stdc++.h>

using namespace std;

int dp[100001], n, k, t;

int main(){
    
    cin >> n >> k;
    
    dp[0]=1;
    
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        for(int j = 0 ; j <= k ; j++){
            if(j-t>=0) dp[j] += dp[j-t];
        }
        
        
        
    }
    
    cout << dp[k] << '\n';
    
    
}
