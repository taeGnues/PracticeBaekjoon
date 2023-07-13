#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    while(T--){
        int N=0, M=0, res=0, tmp=0;
        
        cin >> N >> M;
        vector<int> a(N), b(M);
        
        // lower_bound, upper_bound
        // 1. A, B를 입력받고 순서대로 정렬
        for(int i = 0 ; i < N ; i++) {cin >> a[i];}
        for(int i = 0 ; i < M ; i++) {cin >> b[i];}
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // 2. 주어진 값이 조건에해 해당하는 처음으로 나타나는 위치 찾기 (= lower_bound)
        // 1 1 2 2 3 lowerbound 2일 경우, iterator로 3이 나옴.
        // 3 - 1 = 2개.
        
        for(auto i : a){
            auto pos = lower_bound(b.begin(), b.end(), i);
            res += (int)(pos - b.begin());
            
        }
                
        cout << res << '\n';
        
    }
    return 0;
}

// 못 풀었음!!
