#include <bits/stdc++.h>

using namespace std;
int arr[20][20], N, res=INT_MAX;
bool bd[20];
vector<pair<int, int>> pv;

void combi(int st, vector<int> now){
    if(now.size()==N/2){
        int team1=0;
        int team2=0;
        vector<int> notnow;
        for(int i = 0 ; i < N; i++){
            if(!bd[i]) notnow.push_back(i);
        }
        
        for(int i = 0 ; i < notnow.size(); i++){
            for(int j = 0 ; j < notnow.size(); j++){
                team2+=arr[notnow[i]][notnow[j]];
            }
        }
        
        for(int i = 0 ; i < now.size(); i++){
            for(int j = 0 ; j < now.size(); j++){
                team1+=arr[now[i]][now[j]];
            }
        }
        
        res = min(res, abs(team1-team2));
        return;
    }
    
    for(int i = st+1 ; i < N ; i++){
        now.push_back(i);
        bd[i]=1;
        combi(i, now);
        now.pop_back();
        bd[i]=0;
    }
    
    return;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> v;
    combi(-1, v);
    
    cout << res;
    
    
}
