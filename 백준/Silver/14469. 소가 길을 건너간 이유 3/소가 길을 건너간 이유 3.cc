#include <bits/stdc++.h>

using namespace std;

int N, at, ct, ret;
vector<pair<int, int>> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> at >> ct;
        v.push_back({at, ct});
    }
    
    sort(v.begin(), v.end());
    
    ret = v[0].first;
    for(int i = 0 ; i < v.size() ; i++){
        ret += v[i].second; // 도착시간 넣음.
        
        if((i != v.size()-1) && ret < v[i+1].first){ // 만약 다음 순번 도착까지 여유시간이 있다면 그만큼 기다려야함.
            ret += v[i+1].first - ret;
        }
        
        // 만약 다음순번이 동시에 도착한 상황, 다음순번이 기다려야하는 상황, 그냥 끝나는 시간에 바로 다음순번이 되면 ret += v[i].second
    }
    
    cout << ret;
    
}
