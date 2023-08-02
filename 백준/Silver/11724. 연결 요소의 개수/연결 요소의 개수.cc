#include <bits/stdc++.h>

using namespace std;

int n, m, res;
vector<int> adj[1001];
bool vis[1001];

void dfs(int cur){
    if(vis[cur]) return;
    vis[cur]=1;
    
    for(auto i : adj[cur]){
        if(vis[i]) continue;
        dfs(i);
    }
    
    return;
}

int main(){
    
    cin >> n >> m;
    
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]) {res++; dfs(i);}
    }
    
    cout << res << '\n';
    
}
