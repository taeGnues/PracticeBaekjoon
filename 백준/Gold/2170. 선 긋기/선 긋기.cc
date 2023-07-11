#include <bits/stdc++.h>

using namespace std;

long long n, x, y, res, bs, be;
vector<pair<long long, long long>> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while(n--){
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end());
    
    bs = v[0].first;
    be = v[0].second;
    
    for(auto i : v){
        long long ns = i.first;
        long long ne = i.second;
        
        if(bs <= ns && ns <= be && be <= ne){ // bs x be y 일때
            be = ne; // 끝점 업데이트
        }else if (be <= ns){ // bs be x y일때
            res += (be-bs);
            bs=ns;
            be=ne;
        }
        
    }
    
    res+=be-bs;
    
    cout << res << "\n";
    
}
