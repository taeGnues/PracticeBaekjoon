#include <bits/stdc++.h>

using namespace std;

int dp[1004][2][34], n, m, b[1004];

int go(int idx, int tree, int cnt){
    if(cnt < 0) return -1e9;
    if(idx==n) return cnt>=0 ? 0:-1e9; // 시간이 모두 완료될 시, 종료.
    
    int &mid = dp[idx][tree][cnt];
    if(~mid) return mid; // -(n+1). n==-1이면 무시.
    
    return mid = max(go(idx+1, tree^1, cnt-1), go(idx+1, tree, cnt)) + (tree==b[idx]-1); //
}



int main(){
    
    
    
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0 ; i < n; i++) cin >> b[i];
    
    cout << max(go(0, 1, m-1), go(0,0,m)) << '\n'; // 시간 / 현위치 / 이동횟수
    
    
    
}
