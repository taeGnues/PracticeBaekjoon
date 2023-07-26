#include <bits/stdc++.h>

using namespace std;

int bd[501][501], vis[501][501], n, res, dp[501][501];

int dy[4] = {0, 1, -1, 0};
int dx[4] = {1, 0, 0, -1};

int dfs(int y, int x){
    int &mid = dp[y][x];
    if(mid>=0) return mid;
    mid=1;
    
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny >= n || nx >= n || ny < 0 || nx < 0) continue;
        if(bd[ny][nx] > bd[y][x]) {
            mid = max(mid, dfs(ny, nx) + 1);
        } // 다음에 먹을거보다 작아지면 무시.
    }
    return mid;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> bd[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            res = max(res, dfs(i, j));
        }
    }
    
    cout << res << '\n';
    
}
