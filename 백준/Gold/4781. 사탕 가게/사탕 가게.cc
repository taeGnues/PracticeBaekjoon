#include <bits/stdc++.h>

using namespace std;

int n, m1, m2;
int dp[10001];

int main(){
    
    
    while(true){
        scanf("%d %d.%d", &n, &m1, &m2);
        if(n==0) break;
        int m_int = m1*100 + m2;
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i < n ; i++){
            int c, b1, b2;
            scanf("%d %d.%d", &c, &b1, &b2);
            
            int m_temp = b1*100 + b2;
            
            for(int j = m_temp ; j <= m_int ; j++){
                dp[j] = max(dp[j], dp[j-m_temp] + c);
            }
        }
        
        
        cout << dp[m_int] << '\n';
        
        
    }
    
    
    
    
}
