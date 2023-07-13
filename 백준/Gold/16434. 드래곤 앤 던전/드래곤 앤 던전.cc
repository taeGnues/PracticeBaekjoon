#include <bits/stdc++.h>
typedef long long ll;
// longlong은 1e18 !
using namespace std;

ll N, init_Hatk, res=9e18;
vector<pair<ll, ll>> dungeon;


bool check(ll Hmax){
    ll Hatk = init_Hatk;
    ll Hcur=Hmax;
    
    for(auto i : dungeon){
        
        ll a = i.first;
        ll h = i.second;
        
        if(a<0){ // 몬스터일때
//            while(true){
//
//                // 1. 용사 Hatk 만큼 몬스터 피 깎기
//                h-=Hatk;
//                // 2. 몬스터 피 확인
//                if(h<=0) break;
//                // 3. 몬스터 a 만큼 용사 피 깎기
//                Hcur+=a;
//                // 4. 용사 피 확인
//                if(Hcur<=0) return false;
//            }
            
            ll cnt = h / Hatk + ((h%Hatk) ? 1 : 0);// 몬스터의 체력과 용사의 공격력을 기반으로 몬스터의 공격횟수를 구함
            Hcur += (cnt-1)*a;
            if(Hcur <= 0) return false;
        }
        else{ // 포션일때
            
            Hatk+=a;
            Hcur = min(Hcur+h, Hmax);
        }
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> init_Hatk;

    for(ll i = 0 ; i < N ; i++){
        ll t, a, h;
        cin >> t >> a >> h;
        if(t==1) dungeon.push_back({-1 * a, h});
        if(t==2) dungeon.push_back({a, h});
    }
    
    ll lo = 1;
    ll hi = 1e18 + 4;
    
    
    
    while(lo <= hi){
        ll mid = (lo+hi)/2;
        if(check(mid)){
            res = min(res, mid);
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
