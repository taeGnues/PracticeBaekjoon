#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int n, m;
ll x, y, s;

priority_queue<ll, vector<ll>, greater<>> min_heap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        int tmp=0; cin >> tmp;
        min_heap.push(tmp);
    }
    
    while(m--){ // x 빼고, y 빼고 s로 교체.
        x = min_heap.top();
        min_heap.pop();
        y = min_heap.top();
        min_heap.pop();
        
        s = x+y;
        
        min_heap.push(s);
        min_heap.push(s);
    }
    
    ll res = 0;
    while(min_heap.size()){
        res += min_heap.top();
        min_heap.pop();
    }
    
    cout << res << '\n';
    
    
    
    
    
}
