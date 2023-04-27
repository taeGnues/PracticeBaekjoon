#include <bits/stdc++.h>

using namespace std;

int N, n, people[11], res = INT_MAX;
vector<int> adj[11];
int vis[11], comp[11];

// dfs 공부하자,,
pair<int, int> dfs(int here, int value){ // (현위치, 지금 무슨 선거구인지.)
    vis[here] = 1; // 방문표시
    
    pair<int, int> ret = {1, people[here]}; // 현재 방문한 노드수 (=1) 백트래킹으로 올라가며 다시 return해줌, 인구수 저장.
    
    for(auto i : adj[here]){
        if(comp[i] != value) continue; // 다른 팀이면 무시
        if(vis[i]) continue; // 방문한 곳이면 무시.
        
        pair<int, int> _temp = dfs(i, value);
        ret.first += _temp.first; // 리턴해준 값을 통해 연결된 구역 개수
        ret.second += _temp.second; //리턴해준 값을 통해 총인구수 계산
    }
    
    return ret;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    for(int i = 1 ; i <= N ; i++) cin >> people[i];

    for(int i = 1 ; i <= N ; i++){
        cin >> n;
        for(int j = 0 ; j < n ; j++){
            int tmp;
            cin >> tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i); // 인접 리스트 생성. 양방향임!!
        }
    }
    
    // red blue의 가지수 모두 구해보기 0과 1로 표현!! N개가 있다면, 000...1 ~ 111...0 까지
    for(int i = 1 ; i < (1 << N) - 1 ; i++){
        memset(vis, 0, sizeof(vis));
        memset(comp, 0, sizeof(comp));

        // 0에서 시작할거 한개, 1에서 시작할거 한개 고르기!
        int select1 = -1, select0 = -1;
        
        for(int j = 0 ; j < N ; j++){
            if(i & (1<<j)) {comp[j+1] = 1; select1 = j+1;} // 처음으로 켜져있는 선거구. (1번부터 시작함) & comp에는 각 선거구 정보 저장. (1번은 0, 2번은 1,,, 이런식)
            else select0 = j + 1;
        }
        
        
        pair<int, int> comp1 = dfs(select1, 1); // 1인 선거구
        pair<int, int> comp2 = dfs(select0, 0); // 0인 선거구
        
        int psum = abs(comp1.second - comp2.second); // 인구수 차이
        
        if(comp1.first + comp2.first == N) res = min(res, psum);

    }
   
    
    
    
    // 근데 adj로 2개로 나눠지는지 확인. 이는 각 adj dfs한 결과의 합이 N인지 확인하면 됨.
    // 그때의 인구수 차이를 구해서 갱신
        

    
    
    res == INT_MAX ? cout << -1 : cout << res;
    
    
}
