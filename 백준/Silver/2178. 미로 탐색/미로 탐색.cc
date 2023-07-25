#include <bits/stdc++.h>

using namespace std;

int N, M, bd[101][101], vis[101][101];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main(){
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < M ; j++){
            bd[i][j] = s[j]-'0';
        }
    }
    
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        
        
        for(int i = 0 ; i < 4 ; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            
            if(ny >= N || nx >= M || ny < 0 || nx < 0 || vis[ny][nx]) continue;
            if(bd[ny][nx]==0) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
            
        }
        
        
    }
    
    
    cout << vis[N-1][M-1] << '\n';
}
