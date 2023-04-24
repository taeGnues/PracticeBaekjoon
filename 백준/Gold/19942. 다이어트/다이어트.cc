#include <bits/stdc++.h>

using namespace std;

int foods[20][6];
int now_nutri[6], min_nutri[6];
int cost, res=INT_MAX, N;
vector<pair<int, vector<int>>> ans;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int j = 0 ; j < 4 ; j++){
        cin >> min_nutri[j]; // 0 1 2 3
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> foods[i][j];
        }
    } // 가격 및 영양.
    
    for(int i=0 ; i < (1<<N) ; i++){
        
        vector<int> tmp;
        for(int j = 0 ; j < N ; j++){
            if(i & (1 << j)){
                for(int k = 0 ; k < 4 ; k++) {now_nutri[k] += foods[j][k];}
                cost += foods[j][4];
                tmp.push_back(j+1);
            }
        }
        
        int flag = 1;
        for(int k = 0 ; k < 4 ; k++){
            if(min_nutri[k]==0) continue;
            if(now_nutri[k] < min_nutri[k]) {flag = 0 ; break;}
        } // 개별 영양소 비교.
        
        
        if (flag && cost <= res){
            ans.push_back({cost,tmp});
        }
        
        cost = 0;
        memset(now_nutri, 0, sizeof(now_nutri));
    } // 경우의 수 구하기.
    
    if(!ans.empty()){
        sort(ans.begin(), ans.end());
        cout << ans[0].first << '\n';
        for(auto i : ans[0].second) cout << i << ' ';
    } else{
        cout << "-1";
    }
    
}
