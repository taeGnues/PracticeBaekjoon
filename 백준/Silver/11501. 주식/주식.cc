#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

int t, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while(t--){
        ll res = 0;
        cin >> n;
        vector<int> v;
        for(int i = 0 ; i < n ; i++){
            int tmp; cin >> tmp; v.push_back(tmp);
        }
        
        int maxV = -1;
        for(int i = n-1 ; i >= 0 ; i--){
        
            if(maxV <= v[i]) {
                maxV = v[i];
                continue;
            }
            
            res += (maxV-v[i]);
            
        }
        cout << res << '\n';
    
    }
    
    
    
    
    
    
}
