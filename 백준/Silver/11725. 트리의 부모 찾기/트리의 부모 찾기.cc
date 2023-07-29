#include <bits/stdc++.h>

using namespace std;

int N;
int parent[100001], vis[100001];
vector<int> bd[100001];

void dfs(vector<int> now, int now2){
    
    if(now.size()==0) return;
    
    vis[now2]=1;
    
    for(auto i : now){
        if(vis[i]) continue;
        parent[i] = now2;
        dfs(bd[i], i);
    }
    
    return;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N-1 ; i++){
        int a, b;
        cin >> a >> b;
        bd[a].push_back(b);
        bd[b].push_back(a);
    }
    
    
    
    dfs(bd[1], 1);
    
    
    for(int i = 2 ; i <= N ; i++){
        cout << parent[i] << '\n';
    }
}
