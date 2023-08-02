#include <bits/stdc++.h>

using namespace std;

int N, arr[1001], maxValue, cnt[1001], res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++) {cin >> arr[i];}
    
    for(int i = 0 ; i < N ; i++){
        maxValue = 0;
        for(int j = 0 ; j < N ; j++){
            if(arr[i] > arr[j] && cnt[j] > maxValue){
                maxValue = cnt[j];
            }
            
            cnt[i] = maxValue + 1;
            
            res = max(res, cnt[i]);
        }
        
    }
    
    cout << res << '\n';
    
    
}
