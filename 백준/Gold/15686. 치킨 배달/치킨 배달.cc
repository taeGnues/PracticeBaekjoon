#include <bits/stdc++.h>

using namespace std;

int N, M, bd[51][51], res=INT_MAX;
vector<pair<int, int>> chickens, homes;


void go(int st, vector<pair<int,int>> select_chickens){
    if(select_chickens.size()==M){
        // 1. 치킨집 M개 고르기
        // 2. 고른 치킨집과 집까지의 치킨거리 구하기
        int chicken_distances = 0;
        
        for(auto home : homes){
            int r1 = home.first;
            int c1 = home.second;
            int chicken_distance = INT_MAX;
            for(auto select_chicken : select_chickens){
                // |r1-r2| + |c1-c2|
                int r2 = select_chicken.first;
                int c2 = select_chicken.second;
                int dis = abs(r1-r2)+abs(c1-c2);
                
                chicken_distance = min(chicken_distance, dis);
                
            }
            
            
            chicken_distances += chicken_distance;
        }
        
        res = min(res, chicken_distances);
        
        return;
    }
    
    for(int i = st+1; i < chickens.size() ; i++){
        
        select_chickens.push_back(chickens[i]);
        
        go(i, select_chickens);
        
        select_chickens.pop_back();
        
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> bd[i][j];
            if(bd[i][j]==1) homes.push_back({i, j});
            if(bd[i][j]==2) chickens.push_back({i, j});
        }
    }
    
    vector<pair<int,int>> v;
    go(-1, v);
    
    cout << res << '\n';
}

