#include <bits/stdc++.h>

using namespace std;

int R, C, res;
int bd[25][25], vis[25][25];
int useAlph[26];


int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int dfs(int y, int x, int level){
    vis[y][x] = 1; // 방문
    useAlph[bd[y][x]] = 1; // 해당 알파뱃 사용 체크.
    
    int ret = level;
    
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny > R || nx > C || ny <= 0 || nx <= 0 || vis[ny][nx]) continue;
        if(useAlph[bd[ny][nx]]) continue; // 해당 알파벳이 사용됐다면 무시.
        
        ret = max(ret, dfs(ny, nx, level+1));
        
        vis[ny][nx] = 0;
        useAlph[bd[ny][nx]] = 0; // 원래대로 돌려주기
        
    }
    
    
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    
    
    for(int i = 1 ; i <= R ; i++){ // (1.1) 부터 시작.
        string s="";
        cin >> s;
        
        for(int j = 0 ; j < C ; j++){
            bd[i][j+1] = (s[j]-'A'); // 0~26으로 알파뱃 표현.
        }
    }
    
    res = dfs(1,1,1);
    
    cout << res;
    
}
