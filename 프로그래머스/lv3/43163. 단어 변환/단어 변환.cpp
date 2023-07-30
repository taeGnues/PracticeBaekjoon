#include <bits/stdc++.h>

using namespace std;

int ans=INT_MAX;
string target01;
vector<string> words01;

map<string, int> vis;
bool check(string s1, string s2){
    int chk=0;
    for(int i = 0 ; i < s1.size() ; i++){
        if(s1[i]!=s2[i]) chk++;
    }
    
    return (chk <= 1);
}

void go(string s, int n){
    if(target01==s) {ans=min(ans, n); return;}
    
    vis[s]=1; // 방문표시
    
    for(auto i : words01){
        
        if(check(i, s) && vis[i]!=1){
            vis[i]=1;
            n++;
            
            go(i, n);
            
            vis[i]=0; // 원래대로 돌려두기
            n--;
        }
    }
    
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target)==words.end()) {return 0;}
    
    target01 = target;
    words01 = words;
    
    
    go(begin, 0);
    
    return (ans==INT_MAX ? 0 : ans);
}