#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b; v.push_back({b, a});
    }
    
    sort(v.begin(), v.end()); // day 순으로 정렬. 오름차순.
    
    
    for(int i = 0; i < n; i++){ // 0부터 오름차순으로 올라감.
        pq.push(v[i].second); // 해당 날짜에 맞는 가격 넣기.
        if(pq.size() > v[i].first){ // pq.size()가 해당날짜보다 크면 pop 해주기. ex) 1일 10, 1일 20, 1일 30 (size > 해당day) 이렇게 되면 최소힙이므로 1일 30만 남게됨.
            pq.pop(); // 가장 낮은 최소 가격이 pop됨.
        }
    }
    
    
    while(pq.size()){
        ret += pq.top(); pq.pop(); // 힙에 남은 모든 가격을 합하면 답!
    }
    
    cout << ret << "\n";
}
