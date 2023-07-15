#include <bits/stdc++.h>

using namespace std;

int N, arr[501], cnt[501], maxValue, mxlen, a_nums[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++) {
        cin >> a_nums[i];
        cin >> arr[a_nums[i]];
    }
    
    sort(a_nums, a_nums + N);
    for(int i = 0 ; i < N ; i++){
        maxValue = 0;
        for(int j = 0 ; j < N ; j++){
            if(arr[a_nums[i]] > arr[a_nums[j]] && cnt[a_nums[j]] > maxValue){
                maxValue = cnt[a_nums[j]];
            }
            cnt[a_nums[i]] = maxValue + 1;
            mxlen = max(mxlen, cnt[a_nums[i]]);
            
        }
    }
    
    cout << N-mxlen << '\n';
    
}
