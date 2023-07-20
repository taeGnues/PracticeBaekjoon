#include <bits/stdc++.h>

using namespace std;

int bd[16][16], res, N;

struct pipe{
    int y; //끝점의 정보
    int x;
    int state;
}; // 가로 : 1, 세로 : 2, 대각선 : 3


bool chk_horizontal(int y, int x){ // 수평 이동
    if(bd[y][x+1]==0) return true;
    return false;
}


bool chk_vertical(int y, int x){ // 수직 이동
    if(bd[y+1][x]==0) return true;
    return false;
}

bool chk_diagonal(int y, int x){ // 대각선 방향 이동 가능?
    if(bd[y+1][x]==0 && bd[y][x+1]==0 && bd[y+1][x+1]==0) return true;
    return false;
}


void go(pipe pi){
    if(pi.y==N-1 && pi.x==N-1) {res++; return;} // 끝 점 도달 시 종료
    if(pi.y>=N || pi.x>=N) return;
    
    if(pi.state==1) { // 가로
        if(chk_horizontal(pi.y, pi.x)){
            pipe nxt_pi = {pi.y, pi.x+1, 1};
            go(nxt_pi);
        };
        
        if(chk_diagonal(pi.y, pi.x)){
            pipe nxt_pi = {pi.y+1, pi.x+1, 3};
            go(nxt_pi);
        };
        
        
    }else if(pi.state==2){ // 세로
        if(chk_vertical(pi.y, pi.x)){
            pipe nxt_pi = {pi.y+1, pi.x, 2};
            go(nxt_pi);
        };
        
        if(chk_diagonal(pi.y, pi.x)){
            pipe nxt_pi = {pi.y+1, pi.x+1, 3};
            go(nxt_pi);
        };
        
        
    }else if(pi.state==3){ // 대각선
        if(chk_horizontal(pi.y, pi.x)){
            pipe nxt_pi = {pi.y, pi.x+1, 1};
            go(nxt_pi);
        };
        
        if(chk_vertical(pi.y, pi.x)){
            pipe nxt_pi = {pi.y+1, pi.x, 2};
            go(nxt_pi);
        };
        
        if(chk_diagonal(pi.y, pi.x)){
            pipe nxt_pi = {pi.y+1, pi.x+1, 3};
            go(nxt_pi);
        };
    }
    
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> bd[i][j];
        }
    }
    
    pipe pi = {0,1,1};
    
    go(pi);
    cout << res << '\n';
    
}

//40분, dp X
