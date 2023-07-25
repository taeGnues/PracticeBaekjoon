#include <bits/stdc++.h>

using namespace std;

int N, M, K, x, y, z, res;
int ground[10][10];
int A[10][10];
vector<int> bd[10][10];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;

    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> A[i][j];
            ground[i][j]=5;
        }
    }
    
    for(int i = 0 ; i < M ; i++){
            cin >> x >> y >> z;
            bd[x-1][y-1].push_back(z);
       
    }
    
    while(K--){
        
        // 1. 봄 & 여름 : 나이가 어린 나무부터 자기나이만큼 양분 흡수 / 안되면 즉사. / 나이/2 양분 ++;
        
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(bd[i][j].size()){
                    sort(bd[i][j].begin(), bd[i][j].end());
                    vector<int> tmp;
                    int yangboon=0;
                    int bd_size = (int)bd[i][j].size();
                    for(int k = 0 ; k < bd_size ; k++){
                        
                        if(ground[i][j] >= bd[i][j][k]) {
                            ground[i][j]-=bd[i][j][k]; // 나이만큼 양분 흡수.
                            tmp.push_back(bd[i][j][k]+1); // 양분먹으면 나이 한살 얻음.
                        }else {
                            yangboon += (bd[i][j][k] / 2);
                        }
                    }
                    bd[i][j].clear();
                    bd[i][j] = tmp;
                    ground[i][j] += yangboon;
                }
            } // x,y
        }
        
        // 2. 가을
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(bd[i][j].size()){
                    for(auto k : bd[i][j]){
                        if(k%5==0){
                            for(int l = 0 ; l < 8 ; l++){
                                int ny = i + dy[l];
                                int nx = j + dx[l];
                                
                                if(nx >= N || ny >= N || nx < 0 || ny < 0) continue;
                                
                                bd[ny][nx].push_back(1);
                            } // 인접 8칸에 나이가 1인 나무 생성
                        }
                    }
                }
            }
            
        }
        
        // 3. 겨울
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                ground[i][j] += A[i][j];
            }
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            res += bd[i][j].size();
        }
    }
    cout << res << '\n';
}
