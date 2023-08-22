#include <bits/stdc++.h>
using namespace std;


struct dice{
    int south;
    int north;
    int top;
    int bottom;
    int west;
    int east;
};

int n, m, x, y, k, d;

int bd[21][21];
dice de = {0, 0, 0, 0, 0, 0};

int dx[4] = {0, 0, -1, 1}; // 북 . 남 이동
int dy[4] = {1, -1, 0, 0}; // 동 . 서 이동
// 0 동 1 서 2 북 3 남

int go(int dir){
    int nx = x + dx[dir-1];
    int ny = y + dy[dir-1];

    
    if(nx >= n || ny >= m || nx < 0 || ny < 0) return -1; // 범위를 벗어남
    
    x = nx;
    y = ny;
    // 이동할 위치 업데이트
    
    if(dir == 1){ // 동
        if(bd[x][y] == 0){ // 이동할 칸이 0이면
            bd[x][y]=de.east;
        }else{
            de.east=bd[x][y];
            bd[x][y]=0;
        } // 값 바꾸고 지도 칸에 쓰여있는 숫자로.
        
//        swap(bd[x][y], de.east); // 틀린 논리
//         ? (de.east=0) : (bd[x][y]=0);
        
        de = {de.south, de.north, de.west, de.east, de.bottom, de.top}; // 주사위 굴리기.
        
    }else if(dir == 2){ // 서
        if(bd[x][y] == 0){ // 이동할 칸이 0이면
            bd[x][y]=de.west;
            
        }else{
            de.west=bd[x][y];
            bd[x][y]=0;
        }
        
        de = {de.south, de.north, de.east, de.west, de.top, de.bottom}; // 주사위 굴리기.
        
    }else if(dir==3){ // 북
        if(bd[x][y] == 0){ // 이동할 칸이 0이면
            bd[x][y]=de.north;
            
        }else{
            de.north=bd[x][y];
            bd[x][y]=0;
        }
        de = {de.bottom, de.top, de.south, de.north, de.west, de.east}; // 주사위 굴리기.
        
    }else if(dir==4){ // 남
        if(bd[x][y] == 0){ // 이동할 칸이 0이면
            bd[x][y]=de.south;
            
        }else{
            de.south=bd[x][y];
            bd[x][y]=0;
        }
        
        de = {de.top, de.bottom, de.north, de.south, de.west, de.east}; // 주사위 굴리기.
        
    }
    
    return de.top;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> bd[i][j];
        }
    }
    
    for(int i = 0 ; i < k ; i++){
        cin >> d;
    
        int mid = go(d);
        if(mid!=-1) cout << mid << '\n';
    }
    
    
}
