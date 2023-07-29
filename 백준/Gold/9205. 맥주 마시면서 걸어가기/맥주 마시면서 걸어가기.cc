#include <bits/stdc++.h>

using namespace std;

int t, n, sx, sy, ex, ey;


struct point{
    int x;
    int y;
};


point cvns[103];
int vis[103];

bool bfs(){
    queue<point> q;
    q.push({sx, sy});
    
    while(!q.empty()){
        point cur = q.front(); q.pop();
        
        if(abs(ex-cur.x) + abs(ey-cur.y) <= 1000) return true;
        
        for(int i = 0 ; i < n ; i++){
            if(vis[i]) continue;
            if(abs(cvns[i].x - cur.x) + abs(cvns[i].y - cur.y) <= 1000){
                vis[i]=1;
                q.push({cvns[i].x, cvns[i].y});
            }
        }
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        memset(vis, 0, sizeof(vis));
        
        cin >> n;
        cin >> sx >> sy;
        
        for(int i = 0 ; i < n ; i++){
            cin >> cvns[i].x >> cvns[i].y;
        }
        
        cin >> ex >> ey;
        
        
        bool chk = bfs();
    // 현 위치 ~ 편의점까지 거리. 1000m이내면 통과.
        
        
        
        cout << (chk ? "happy" : "sad") << '\n';
        
    }
    
    
    
    
    
    
}
