#include <bits/stdc++.h>

using namespace std;

int N, res=INT_MAX;
int bd[25]; // row

void go(int here){
    if(here == N+1){
        int sum = 0;
        for(int i = 1 ; i <= (1<<(N-1)) ; i*=2){
            
            int cnt = 0;
            for(int j = 0 ; j < N ; j++) if(bd[j]&i) cnt++; // T의 개수 세기.
            
            sum += min(cnt, N-cnt); // T의 개수가 H의 개수보다 많을 경우 뒤집어주기.
            
        }
        
        res = min(sum, res);
        
        return;
    } // 끝점에 도착. 각 col에서 T가 H보다 많은 것은 뒤집기!!
    
    
    go(here+1); // 안뒤집을 때
    bd[here] = ~bd[here];
    go(here+1); // 뒤집을 때
    bd[here] = ~bd[here]; // 원상 복구.
    
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        string tmp="";
        cin >> tmp;
        
        int value = 1;
        for(int j = 0 ; j < N ; j++){
            if(tmp[j]=='T') bd[i] |= value; // j번째 비트 키기.
            value *= 2;
        }
    }
    
    go(0);
    
    cout << res;
    
    
    return 0;
}
