#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dp[21][102], arth[101], N;


ll go(ll n, ll level){
    if(level == N-2) {
        if(n==arth[N-1]) return 1; // 마지막값과 같음.
        return 0; // 마지막값과 다름.
    }
    
    ll &res = dp[n][level];
    if(res) return res;
    
    ll npl = n+arth[level+1];
    ll nmi = n-arth[level+1];
    
    
    if(npl >= 0 && npl <= 20 && nmi >= 0 && npl <= 20) {res = go(npl, level+1) + go(nmi, level+1);}
    else if(npl < 0 || npl > 20) {res = go(nmi, level+1);}
    else if(nmi < 0 || nmi > 20) {res = go(npl, level+1);}
    else if((nmi < 0 || nmi > 20) && (npl < 0 || npl > 20)) {res = 0;}
    
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    cin >> N;
    for(ll i = 0 ; i < N ; i++) cin >> arth[i];
    
    
    
    cout << go(arth[0], 0) << '\n';

}
