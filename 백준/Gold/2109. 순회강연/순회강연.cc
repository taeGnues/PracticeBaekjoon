#include <bits/stdc++.h>

using namespace std;

int n, p, d;
priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
vector<pair<int, int>> v; // {day, p}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> p >> d;
        v.push_back({d, p});
    }
    
    sort(v.begin(), v.end());
    
    for(auto i : v){
        pq.push(i.second);
        while(pq.size()>i.first){
            pq.pop();
        }
    }
    
    int res = 0;
    while(pq.size()){
        res+=pq.top();
        //cout << pq.top() << '\n';
        pq.pop();
        
    }
    cout << res << '\n';
    
}
