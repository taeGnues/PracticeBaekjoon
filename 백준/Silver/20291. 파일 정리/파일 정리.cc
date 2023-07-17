#include <bits/stdc++.h>

using namespace std;

int N;
map<string, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        string filename;
        cin >> filename;
        int pos = (int)filename.find(".");
        int fend = (int)filename.length();
        string ext = filename.substr(pos+1, fend);
        
        m[ext]++;
    }
    
    for(auto i : m){
        cout << i.first << ' ' << i.second << '\n';
    }
    
    
}
