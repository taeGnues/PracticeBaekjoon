#include <bits/stdc++.h>

using namespace std;

int N, K, res;
int alphs[26];
int words[55];


int count(int mask){
    int cnt = 0;
    for(auto word : words){
        if(word && (word & mask) == word) cnt++;
    }
    return cnt;
}

int go(int index, int k, int mask){ // mask는 지금까지 배운 글자를 의미. index는 글자 a,b,c,d, ... k는 남은 배움 횟수.
    if(k<0) return 0;
    if(index==26) return count(mask);
    int ret = go(index+1, k-1, mask | (1<<index)); // 다음 글자 배움.
    
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        ret = max(ret, go(index+1, k, mask)); // 해당글자 안배우고 넘어감. a,n,t,i,c는 반드시 배워야하는 글자임!!
    }
    
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        for (char str : s){
            words[i] |= (1<< (str-'a'));
        }
        
        
    }
    
    cout << go(0, K, 0);
    
    
    
    return 0;
    
}
