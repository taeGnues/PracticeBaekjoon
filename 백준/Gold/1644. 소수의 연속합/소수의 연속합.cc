#include <bits/stdc++.h>

using namespace std;

int chk[4000001];
int N, res;
vector<int> era(int mx_n){
    vector<int> v;
    for(int i = 2; i <= mx_n ; i++){
        
        if(chk[i]) continue;
        for(int j = 2*i ; j <= mx_n; j+=i) {chk[j]=1;}
        
    }
    
    for(int i = 2; i <= mx_n ; i++){
        if(chk[i]==0) v.push_back(i);
    }
    
    return v;
    
} // 에라토스테네스의 체


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    vector<int> now_pri = era(N);
    int sum = 0, lo=0, hi=0;
    while(1){
        
        if(sum>=N) sum -= now_pri[lo++];
        else if(hi==now_pri.size()) break;
        else sum+=now_pri[hi++];
        
        if(sum==N) res++;
        
    }

    
    
    cout << res;
    
}
