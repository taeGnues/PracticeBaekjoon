#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll X, Y, res=1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> X >> Y;
    
    ll lo = 1;
    ll hi = 1e18;
    
    ll Z = 100*double(Y)/X;
    if(Z>=99){
        cout << -1 << '\n';
        return 0;
    }
    bool chk=0;
    while(lo <= hi){
        ll mid = (lo+hi)/2;
        ll Z2 = double(mid+Y)/(mid+X)*100;
        if(Z<Z2){
            res = min(res, mid);
            hi = mid - 1;
            chk=1;
        }else{
            lo = mid + 1;
        }
    }
    
     cout << (chk ? res : -1) << '\n';
    
    return 0;
}
