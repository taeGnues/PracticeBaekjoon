#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, C, tmp;
map<int, int> m1, m2; // 해당 수 : 빈도수, 해당 수 : 위치
vector<pair<int, int>> v; // 정렬용

bool cmp(pair<int, int> a, pair<int, int> b){
    if(m1[a.X] == m1[b.X]) return m2[a.X] < m2[b.X]; // 빈도수 같다면 나온순서
    return m1[a.X] > m1[b.X]; // 우선 빈도수 큰 순서
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp; m1[tmp]++; // 빈도수 증가
        if(m2[tmp]==0) m2[tmp] = i+1; // 숫자 나온 순서
    }
    
    for(auto a : m1) v.push_back({a.X, a.Y}); // 해당 숫자 : 빈도수
    
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto a : v)
        while(a.Y--) cout << a.X << ' ';
    
}
