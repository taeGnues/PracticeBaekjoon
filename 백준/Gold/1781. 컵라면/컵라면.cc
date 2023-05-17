#include <bits/stdc++.h>

using namespace std;

int N, dl, cups, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        
        cin >> dl >> cups;
        v.push_back({dl, cups});
        
        
    }
    
    sort(v.begin(), v.end());
    
    for(auto i : v){
        pq.push(i.second);
        
        while(pq.size() > i.first){
            pq.pop();
        }
        
    }
    
    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    
    cout << ret <<'\n';
    
}
