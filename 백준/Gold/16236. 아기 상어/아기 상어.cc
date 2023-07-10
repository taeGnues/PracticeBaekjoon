#include <bits/stdc++.h>

using namespace std;

int N, bd[21][21], vis[21][21], res;

int shark_size=2, shark_eating;
pair<int, int> shark_now;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> bd[i][j];
            if(bd[i][j]==9){
                shark_now = {i, j};
            }
            
        }
    }
    
    
    while (true) {
        
        queue<pair<int, int>> q;
        vector<pair<int, int>> can_eat_fishes;
        memset(vis, 0, sizeof(vis));
        
        // 시작 위치
        q.push(shark_now);
        vis[shark_now.first][shark_now.second] = 1;
        
        // 1. bfs로 최단거리로 먹을 수 있는 물고기 찾기
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            
            for(int dir = 0 ; dir < 4 ; dir++){
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                
                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(vis[ny][nx] || bd[ny][nx] > shark_size) continue; // 자기보다 몸짓 큰녀석은 통과 X
                
                q.push({ny, nx});
                vis[ny][nx] = vis[cur.first][cur.second] + 1; // 각칸의 이동거리
                if(bd[ny][nx] < shark_size && bd[ny][nx]) can_eat_fishes.push_back({ny, nx});
                // 먹을 수 있는 물고기 저장
            }
        }
        
         // -- 3+6
        // 더이상 먹을 수 있는 물고기가 없다면 종료
        if(can_eat_fishes.empty()){
            cout << res << '\n';
            return 0;
        }
        
        // 2. 먹을 수 있는 물고기 중 한 개 고르기
        // 2-1. 거리가 가장가까운거
        int min_dis = INT_MAX;
        vector<pair<int,int>> same_can_eat_fishes; // 거리 가까운 물고기들
        for(auto fish : can_eat_fishes){
            int r = fish.first;
            int c = fish.second;
            
            if(min_dis == vis[r][c]){
                same_can_eat_fishes.push_back({r, c});
            }else if(min_dis > vis[r][c]){
                min_dis = vis[r][c];
                same_can_eat_fishes.clear();
                same_can_eat_fishes.push_back({r, c});
            }
        }
        // 2-2. 거리가 같은 물고기들 중 가장 위에 있고, 가장 왼쪽. (i, j)이면 i가 작고 j가 작은거
        sort(same_can_eat_fishes.begin(), same_can_eat_fishes.end());
        
        
        pair<int, int> select_fish = same_can_eat_fishes[0];
        
        // 3. 먹기 & 이동
        bd[shark_now.first][shark_now.second] = 0;
        
        int nxt_shark_y = select_fish.first;
        int nxt_shark_x = select_fish.second;
        
        res += vis[nxt_shark_y][nxt_shark_x]-1;
        shark_now = {nxt_shark_y, nxt_shark_x};
        
        
        // 4. 조건에 맞는지 확인하고 size 늘리기
        shark_eating++;
        if(shark_size==shark_eating){
            shark_size++;
            shark_eating = 0;
        }
        
    }
}
