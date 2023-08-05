#include <bits/stdc++.h>

using namespace std;

int N, K;
int wt, wm, bt, bm, res;
int dp[101];
pair<int, int> w[101]; // 걸린시간 , 모금액
pair<int, int> b[101];

void go(int now_time, int now, int money){ // 소요 시간, 현재 구간, 지금까지의 모금액
    if(now_time>K) return; // 소요시간 넘어가면 종료
    if(now==N){res = max(res, money); return;} // 위치 도달시 종료
    
    go(now_time+w[now].first, now+1, money+w[now].second); // 걷기
    go(now_time+b[now].first, now+1, money+b[now].second); // 자전거타기
    
    return;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    
    for(int i = 0 ; i < N ; i++){
        
        cin >> wt >> wm >> bt >> bm;
        w[i] = {wt, wm};
        b[i] = {bt, bm};
    }
    
    go(0, 0, 0);
    
    cout << res << '\n';
}
