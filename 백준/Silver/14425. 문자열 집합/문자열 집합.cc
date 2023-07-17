#include <bits/stdc++.h>

using namespace std;

int N, M, res;

map<string, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        m[s]++;
    }
    
    for(int i = 0 ; i < M ; i++){
        string s;
        cin >> s;
        if(m[s]) res++;
    }
    
    cout << res << '\n';
    
    
}
