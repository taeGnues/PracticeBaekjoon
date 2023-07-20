#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll N=-1;
ll st[31][31];


ll go(ll n, ll h){ // n은 1조각 개수 h는 반조각 개수
    if(n==0 && h==0) {return 1;}

    ll &res = st[n][h];
    if(res) return res;

    if(n!=0) {
        res += go(n-1, h+1);
    } // 1개꺼내서 반조각 먹고 반조각 넣기
    
    if(h!=0) {
        res += go(n, h-1);
    } // 반조각 꺼내서 먹기
    
    
    return res;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        
        cin >> N; if(N==0) break;
        cout << go(N, 0) << '\n';
      
        
        
    }
    
    
    
    
    
}
