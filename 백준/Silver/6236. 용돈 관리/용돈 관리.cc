#include <bits/stdc++.h>

using namespace std;

int N, M, spendmoney[100001], hi, lo, mid, res=INT_MAX;

bool check(int mid){
    int nums=0, now=0;
    while (now<N) {
        int spends = 0;
        for(int i = now ; i < N ; i++){
            spends += spendmoney[i];
            now++;
            
            if(spends > mid){
                spends -= spendmoney[i];
                now--;
                break;
            }
        }
        nums++;
        
    }
    
    
    return nums<=M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++) {
        cin >> spendmoney[i];
        lo = max(spendmoney[i], lo);
        hi += spendmoney[i];
    }
    
    while (lo <= hi) {
        mid = (lo+hi)/2;
        if(check(mid)){
            res = min(res, mid);
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    
    
    cout << res << '\n';
    return 0;
}
