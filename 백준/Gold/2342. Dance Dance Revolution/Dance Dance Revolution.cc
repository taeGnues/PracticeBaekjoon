#include <bits/stdc++.h>
#define INF 500000;

using namespace std;

int arr[100001], N;
int dp[100001][5][5]; // 현위치 / 왼발, 오른발

int po(int from, int to){ // from 에서 to로.
    if(from==to) return 1; // 같은지점 한번 더 누를 시 1.
    else if(from==0) {return 2;} // 시작지점 0이면 힘은 2.
    else if(abs(from-to)==2) {return 4;} // 서로 반대방향이면 3<->1, 2<->4
    else {return 3;} // 그밖에 모든 경우는 3
}

int go(int level, pair<int, int> now){
    if(level==N) return 0;
    
    int &mid = dp[level][now.first][now.second];
    
    if(mid) return mid;
    
    mid = min(go(level+1, {arr[level], now.second}) + po(now.first, arr[level]),
              go(level+1, {now.first, arr[level]}) + po(now.second, arr[level])); // 왼발 , 오른발
    
    return mid;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    
    for(int i = 0 ;; i++){
        cin >> arr[i];
        if(arr[i]==0) {N=i; break;}
    }
    
    
    
    cout << go(0, {0,0}) << '\n';
    
}
