#include <bits/stdc++.h>

using namespace std;

int N, M, T, res;

vector<int> plate[51];

void go(int x, int d, int k){
    
    // 1. x의 배수인 원판을 선택. d방향 k칸 회전
    if(d==1){ // 반시계 방향
        for(int i = x ; i <= N ; i+=x){
            rotate(plate[i].begin(), plate[i].begin()+k, plate[i].end());
        }
    } else if(d==0){ // 시계방향
        for(int i = x ; i <= N ; i+=x){
            rotate(plate[i].rbegin(), plate[i].rbegin()+k, plate[i].rend());
        }
    }
    
    // 2. 원판에 수가 남아 있으면(없는 숫자는 0로 표시), 인접하면서 수가 같은 것을 모두 찾는다.
    vector<pair<int, int>> poss; // 겹치는 원판 위 숫자들들 위치
    
    // 2-1. (i, j++)
    for(int i = 1 ; i <= N ; i++){
        
        //    (i, 0)은 (i, 1), (i, M-1)과 인접하다.
        if(plate[i][0]==plate[i][1]){
            poss.push_back({i,0});
            poss.push_back({i,1});
        }
        
        if(plate[i][0]==plate[i][M-1]){
            poss.push_back({i,0});
            poss.push_back({i,M-1});
        }
        
        //    (i, M-1)은 (i, M-2), (i, 0)과 인접하다.
        if(plate[i][M-1]==plate[i][M-2]){
            poss.push_back({i,M-1});
            poss.push_back({i,M-2});
        }
        
        if(plate[i][M-1]==plate[i][0]){
            poss.push_back({i,M-1});
            poss.push_back({i,0});
        }
        
        
        for(int j = 1 ; j <= M-2 ; j++){
            //    (i, j)는 (i, j-1), (i, j+1)과 인접하다. (1 ≤ j ≤ M-2)
            if(plate[i][j]==plate[i][j-1]){
                poss.push_back({i,j});
                poss.push_back({i,j-1});
            }
            
            if (plate[i][j]==plate[i][j+1]){
                poss.push_back({i,j});
                poss.push_back({i,j+1});
            }
        }
    }
    
    
    // 2-2. (i++, j-1)
    for(int j = 0 ; j < M ; j++){
        //    (N, j)는 (N-1, j)와 인접하다.
        if(plate[N][j]==plate[N-1][j]){
            poss.push_back({N, j});
            poss.push_back({N-1, j});
        }
    
        //    (1, j)는 (2, j)와 인접하다.
        if(plate[1][j]==plate[2][j]){
            poss.push_back({1,j});
            poss.push_back({2,j});
        }
        
        
        
        for(int i = 2 ; i <= N-1 ; i++){
            //    (i, j)는 (i-1, j), (i+1, j)와 인접하다. (2 ≤ i ≤ N-1)
            if(plate[i][j]==plate[i-1][j]){
                poss.push_back({i,j});
                poss.push_back({i-1,j});
            }
            
            if (plate[i][j]==plate[i+1][j]){
                poss.push_back({i,j});
                poss.push_back({i+1,j});
            }
        }
    }
    
    bool chk=0;
    
    if(poss.size()){ // 원판 숫자 확인
        for(auto pos : poss){
            int i = pos.first;
            int j = pos.second;
            
            if(plate[i][j]) {chk=1; break;}
        }
    }
    
    
    // 3-1. 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
    if(chk){
        for(auto pos : poss){
            int i = pos.first;
            int j = pos.second;
            
            plate[i][j] = 0;
        }
    }
    else{ // 3-2. 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
        int sum=0;
        int cnt=0;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(plate[i][j]!=0) cnt++;
                sum+=plate[i][j];
            }
        }
        
        float avg = (float)sum/cnt;
//        cout << '\n' << avg << '\n';
        
        for(int i = 1 ; i <= N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(plate[i][j]!=0){
                    if((float)plate[i][j]>avg){
                        plate[i][j]--;
                    }else if((float)plate[i][j]<avg){
                        plate[i][j]++;
                    }
                }
            }
        }
    }
    
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> T;
    
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < M ; j++){
            int tmp;
            cin >> tmp;
            plate[i].push_back(tmp);
        }
    }
    
    
    
    for(int p = 0 ; p < T ; p++){
        int x, d, k;
        cin >> x >> d >> k;
        go(x, d, k);
//
//        cout << "=== "<< p+1 << "번 시행=========\n";
//        for(int i = 1 ; i <= N ; i++){
//            cout << i <<"번 원판 : ";
//            for(int j = 0 ; j < M ; j++){
//                cout << plate[i][j] << ' ';
//            }
//            cout << '\n';
//        }
    }
    
    for(int i = 1 ; i <= N ; i++){
    
        for(int j = 0 ; j < M ; j++){
    
            res+=plate[i][j];
        }
    }
    
    cout << res << '\n';
    
    
}

// 1시간 51분 8초
// 인접한 부분 찾기에서 실수가 많았음.
