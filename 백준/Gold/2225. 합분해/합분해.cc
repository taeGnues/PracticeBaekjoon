#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[201][201];

int main(){
    
    cin >> N >> K;
    
    for(int i = 1 ; i <= K ; i++){
        dp[1][i] = i;
    }
    
    for(int i = 1 ; i <= N ; i++){
        dp[i][1] = 1;
    }
    
    for(int i = 2 ; i <= N ; i++){
        for(int j = 2 ; j <= K ; j++){
            
            
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%1000000000;
            
            
        }
        
        
    }
    
    cout << dp[N][K] << '\n';
    
}
