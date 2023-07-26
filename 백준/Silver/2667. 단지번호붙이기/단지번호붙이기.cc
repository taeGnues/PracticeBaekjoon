#include <bits/stdc++.h>

using namespace std;

int N, bd[26][26], chk=1, vis[26][26];
int danzis[125];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};


void bfs(int i, int j){
    
    
    queue<pair<int, int>> q;
    q.push({i, j});
    bd[i][j]=chk;
    vis[i][j]=1; // 시작지점 표시
    danzis[chk]=1;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        
        for(int dir = 0 ; dir < 4 ; dir++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            
            if(ny >= N || nx >= N || ny < 0 || nx < 0 || vis[ny][nx]) continue;
            if(!bd[ny][nx]) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = 1;
            bd[ny][nx] = chk;
            danzis[chk]++;
        }
        
    }
    
    chk++;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < N ; j++){
            bd[i][j] = s[j]-'0';
            
        }
    }
    
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(bd[i][j]!=0 && vis[i][j]==0){
                bfs(i, j);
            }
        }
        
    }
    
    
    sort(danzis, danzis+chk);
    
    cout << chk-1 << '\n';
    for(int i = 1 ; i < chk ; i++){
        cout << danzis[i] << '\n';
    }
    
    
    
    
}
