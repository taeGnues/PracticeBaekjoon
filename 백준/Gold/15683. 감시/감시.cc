#include <bits/stdc++.h>

using namespace std;

int N, M, bd[9][9], res=INT_MAX;
int vis[9][9];

struct cctv{
    int no; // 종류
    int dir; // 방향
    pair<int,int> pos;
};// 0 1 2 3 오른쪽 아래 왼쪽 위쪽

vector<cctv> cctvs;

// 0 1 2 3 오른쪽 아래 왼쪽 위쪽
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void check(){ // 사각지대 확인
    int chk=0;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(vis[i][j]==0 && bd[i][j]!=6) chk++;
        }
    }
    
    res = min(chk, res);
    
    return;
}

void overwatch(int d, int pos_y, int pos_x){ // 감시
    if(d==2 || d==0) { // 오른쪽 왼쪽
        
        for(int k = pos_x ; ; k+=dx[d]){
            if(k > M || k < 0) break;
            if(bd[pos_y][k]==6) {vis[pos_y][k]=6; break;} // 벽을 만날시 중단
            vis[pos_y][k] = -1;
        }
    }
    else { // 위 아래
        
        for(int k = pos_y ; ; k+=dy[d]){
            if(k > N || k < 0) break;
            if(bd[k][pos_x]==6){vis[k][pos_x]=6; break;} // 벽을 만날시 중단
            vis[k][pos_x] = -1;
        }
    }
    
    return;
}

void go(int st, vector<cctv> v){
    if(v.size()==cctvs.size()){
        memset(vis, 0, sizeof(vis));
        
        
        for(auto i : v){ // 각 cctv에 대해 감시
            int pos_y = i.pos.first;
            int pos_x = i.pos.second;
            int d = i.dir;
            
            
            switch (i.no) {
                case 1:
                    overwatch(d, pos_y, pos_x);
                    break;
                case 2:
                    if(d==2 || d==0) {
                        overwatch(2, pos_y, pos_x);
                        overwatch(0, pos_y, pos_x);
                    } else{
                        overwatch(1, pos_y, pos_x);
                        overwatch(3, pos_y, pos_x);
                    }
                    break;
                case 3:
                    if(d==0) {
                        overwatch(3, pos_y, pos_x);
                        overwatch(0, pos_y, pos_x);
                    } else{ // 3 2 2 1 1 0
                        overwatch(d, pos_y, pos_x);
                        overwatch(d-1, pos_y, pos_x);
                    }
                    break;
                case 4:
                    // 0 1 2 , 1 2 3
                    if(d==0 || d== 1){
                        overwatch(d, pos_y, pos_x);
                        overwatch(d+1, pos_y, pos_x);
                        overwatch(d+2, pos_y, pos_x);
                    } else{ // 0 2 3 , 0 1 3
                        overwatch(0, pos_y, pos_x);
                        overwatch(4-d, pos_y, pos_x);
                        overwatch(3, pos_y, pos_x);
                    }
                    break;
                case 5:
                    overwatch(0, pos_y, pos_x);
                    overwatch(1, pos_y, pos_x);
                    overwatch(2, pos_y, pos_x);
                    overwatch(3, pos_y, pos_x);
                    break;
            }
        }
        
        check(); // 사각지대 확인
        
        return;
    }
    
    
    // cctv 선택 후 회전시키기
    for(int i = st + 1 ; i < cctvs.size() ; i++){
        
        cctvs[i].dir=0; // 오른쪽
        v.push_back(cctvs[i]);
        go(i, v);
        
        v.pop_back();
        cctvs[i].dir=1; // 아래쪽
        v.push_back(cctvs[i]);
        go(i, v);
        
        v.pop_back();
        cctvs[i].dir=2; // 왼쪽
        v.push_back(cctvs[i]);
        go(i, v);
        
        v.pop_back();
        cctvs[i].dir=3; // 위쪽
        v.push_back(cctvs[i]);
        go(i, v);
    }
    
    
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M; j++){
            cin >> bd[i][j];
            if(bd[i][j] < 6 && bd[i][j]){
                cctvs.push_back({bd[i][j], 0, {i, j}});
            }
        }
    }
    
    vector<cctv> v;
    go(-1, v);
    
    cout << res << '\n';
    
}
