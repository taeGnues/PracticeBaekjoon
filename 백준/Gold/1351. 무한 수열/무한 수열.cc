#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N, P, Q, res;
map<tuple<ll, ll, ll>, ll> m; // 해당 상태 : 해당 값

ll go(ll n, ll a1, ll a2){
    if(n==0) return 1;
    tuple<ll, ll, ll> tl1 = make_tuple(a1, a1/P, a1/Q);
    tuple<ll, ll, ll> tl2 = make_tuple(a2, a2/P, a2/Q);
    
    ll chk1 = m[tl1];
    ll chk2 = m[tl2];
    // 해당값 존재 유무 확인
    
    if(chk1 && chk2) return chk1 + chk2;
    else if(chk1) {
        m[tl2] = go(a2, a2/P, a2/Q);
        return chk1 + m[tl2];
        
    }
    else if(chk2) {
        m[tl1] = go(a1, a1/P, a1/Q); // 값추가
        return chk2 + m[tl1];
    }
    
    
    m[tl1] = go(a1, a1/P, a1/Q); // 값추가
    m[tl2] = go(a2, a2/P, a2/Q);
    
    
    return m[tl1] + m[tl2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    cin >> N >> P >> Q;
    
    
    res = go(N, N/P, N/Q);
    
    
    cout << res << '\n';
    
}
