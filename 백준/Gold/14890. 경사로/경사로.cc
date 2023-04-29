#include <bits/stdc++.h>

using namespace std;

int N, L, res;
int bd[110][110], cop[110][110];

void solve(int a[110][110]){
    for(int i = 0 ; i < N ; i++){
        int cnt = 1;
        
        int j;
        for(j = 0 ; j < N-1 ; j++){
            if(a[i][j] == a[i][j+1]) cnt++; // 같은 경우 cnt 늘려주기
            else if((a[i][j]+1 == a[i][j+1]) && cnt >= L) cnt = 1;// 오르막 경사
            else if((a[i][j]-1 == a[i][j+1]) && cnt >= 0) cnt = -L+1; // 내리막 경사
            else break;
        }
        
        if(j == N-1 && cnt >= 0) res++;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> bd[i][j];
            cop[j][i] = bd[i][j]; // 대칭입력받기.
        }
    }
    
    solve(bd); solve(cop);
    
 

    cout << res;
}
