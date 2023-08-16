#include <bits/stdc++.h>

using namespace std;

int N, res;
bool isNotPrime[4000001];
vector<int> primes;

void erasto(int n){
    for(int i = 2 ; i < 4000001 ; i++){
        if(isNotPrime[i]) continue;
        for(int j = 2*i ; j < 4000001 ; j+=i){
            isNotPrime[j]=true;
        }
    }
    
    for(int i = 2 ; i <= n ; i++) {
        if(!isNotPrime[i]) {
            primes.push_back(i);
        }
    }
}

bool check(int st, int ed){
    int r = 0;
    for(int i = st ; i < ed ; i++){
        r+=primes[i];
        if(r==N) {res++;}
        if(r>N) {return true;}
    }
    
    
    return false;
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    erasto(N); // 에라스토테네스 체
    
    int sum=0,st = 0, ed = 0;
    
    while(true){
        if(sum>=N) sum -= primes[st++];
        else if(ed==primes.size()) break;
        else sum+=primes[ed++];
        
        if(sum==N) res++;
    }
    
    
    
    cout << res << '\n';
    
    
    
}
