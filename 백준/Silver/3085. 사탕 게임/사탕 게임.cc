#include <bits/stdc++.h>

using namespace std;

char bd[51][51];
int N, res;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void go(){ // 사탕 최대개수 찾기
    
    int chk=0;
    char tmp = bd[0][0];
    
    for(int k = 0; k < N; k++){ // 가로 방향으로 찾기
        tmp = bd[k][0];
        
        for(int l = 0 ; l < N ; l++){
            if(bd[k][l]==tmp) chk++;
            else{
                res = max(res, chk);
                tmp = bd[k][l];
                chk=1;
            }
        }
        res = max(res, chk);
        chk=0;
    }
    
    chk=0;
    tmp = bd[0][0];
    for(int l = 0; l < N; l++){ // 세로 방향으로 찾기
        tmp = bd[0][l];
        
        for(int k = 0 ; k < N ; k++){
            if(bd[k][l]==tmp) chk++;
            else{
                res = max(res, chk);
                tmp = bd[k][l];
                chk=1;
            }
        }
        res = max(res, chk);
        chk=0;
    }
}

void candyswap(int y, int x, int ny, int nx){ // 인접한 사탕 교체
    char tmp = bd[y][x];
    bd[y][x] = bd[ny][nx];
    bd[ny][nx] = tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < N ; j++){
            bd[i][j] = s[j];
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            
            for(int dir = 0 ; dir < 4 ; dir++){ // 바꿀 사탕 선택
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                
                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                
                candyswap(i, j, ny, nx); // 바꾸기
                
                go();
                
                candyswap(i, j, ny, nx); // 원래대로 돌려두기
            }
            
            
        }
    }
    
    cout << res <<'\n';
    
}

/*
5
CPZCC
ZYCPZ
CYYPZ
ZPZCC
CCPYY
 
 
3
 */

