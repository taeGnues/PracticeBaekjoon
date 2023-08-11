#include <bits/stdc++.h>

using namespace std;


int dp[1000001], dp2[1000001], N;

int go(int cal){
    if(cal<1) return INT_MAX;
    if(cal==1) return 0;
    
    int &mid = dp[cal];
    if(mid!=INT_MAX) return mid;
    
    if(cal%3==0){
        int m1 = go(cal/3)+1;
        if(mid > m1){
            dp2[cal]=cal/3;
            mid = m1;
        }
    }
    
    if(cal%2==0){
        int m2 = go(cal/2)+1;
        if(mid > m2){
            dp2[cal]=cal/2;
            mid = m2;
        }
    }
    
    int m3 = go(cal-1)+1;
    if(mid > m3){
        dp2[cal]=cal-1;
        mid = m3;
    }
    
    
    return mid;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(&dp[0], &dp[0]+1000001, INT_MAX);
    
    cin >> N;
    
    
    int answer = go(N);
    
    cout << answer << '\n';
    
    cout << N << ' ';
    for(int i = N; i > 1; i=dp2[i]){
        cout << dp2[i] << ' ';
    }
    
    cout << '\n';
}
