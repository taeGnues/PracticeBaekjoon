#include <bits/stdc++.h>

using namespace std;

int N, arr[1001], cnt[1001], prev_idx[1001], idx=-1, maxValue, res, chk, mxV;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    memset(prev_idx, -1, sizeof(prev_idx)); // -1로 초기화
    
    for(int i = 0 ; i < N ; i++) cin >> arr[i];
    
    if(N==1){
        cout << 1 << '\n';
        cout << arr[0] << '\n';
        return 0;
    }
    
    for(int i = 0 ; i < N ; i++){
        maxValue = 0;
        mxV = 0;
        for(int j = 0 ; j < N ; j++){
            if(arr[i] > arr[j] && cnt[j] > maxValue){
                maxValue = cnt[j];
                prev_idx[i] = j;
            }
            
            cnt[i] = maxValue + 1;
            if(res < cnt[i]){
                res = cnt[i];
                idx = i;
            }
        }
    }
    
    
    deque<int> ans;
    
    cout << res << '\n';
    for(int i = idx ; i > -1 ; i=prev_idx[i]) {
        ans.push_front(arr[i]);
    }
    for(auto i : ans) cout << i << ' ';
    cout << '\n';
    
    
    
    
}
