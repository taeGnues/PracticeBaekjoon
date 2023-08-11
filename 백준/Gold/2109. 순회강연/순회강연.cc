#include <bits/stdc++.h>

using namespace std;
int n, d, p, res;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> p >> d;
        v.push_back({d, p});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0 ; i < n ; i++){
        pq.push(v[i].second);
        while(pq.size()>v[i].first) pq.pop(); 
        // 날짜가 1일이면 큐에 한개만남기기. (마지막에 남은 값이 바로 최대값이 됨)
    }
    
    while(pq.size()){
        res+=pq.top();
        pq.pop();
    }
    
    cout << res << '\n';
    
    
    
}
