#include <bits/stdc++.h>

using namespace std;

int T, N, M, A, B; // 체크해야할 그래프의 수, node 수, edge 수

vector<int> graph[1004];
int vis[1004];

int dfs(int here){
    vis[here] = 1; // 방문
    int ret = 1;
    
    if(graph[here].size()){
        for(auto i : graph[here]){

            if(vis[i]) continue;
            
            ret += dfs(i);
        }
    }
    
    
    return ret;
}

bool isTree(){
    
    if(N==1) return true;
    if(dfs(1) != N || M != (N-1)) return false; // Vertex = Edge - 1
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    while(T--){
        cin >> N >> M; // 1부터 N까지의 노드
        for(int i = 0 ; i < M ; i++){
            
            cin >> A >> B;
            graph[A].push_back(B);
            graph[B].push_back(A);
        }
        
        if(isTree()){
            cout << "tree\n";
        }else{
            cout << "graph\n";
        };
        for(int i = 0 ; i <= 1004 ; i++) graph[i].clear();
        // for(auto i : graph) {if(i.size()) i.clear();} // 초기화.
        memset(vis, 0, sizeof(vis));
        // T개의 그래프 개수가 주어지고, 각각의 그래프에 대해 N, M이 주어짐.
        // M개의 라인 동안 A,B 가 주어짐.
    }
}

// 트리의 조건.
// 0) 모든 노드에 접근가능.  ~ isTree() => 모든 노드에 접근해보는 dfs 만약 아니라면? -> 나가리. (개수가 N이 아니면)
// Vertex = Edge - 1

