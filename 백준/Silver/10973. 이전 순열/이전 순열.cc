#include <bits/stdc++.h>

using namespace std;

int N, res;
vector<int> v;
vector<int> origin_v;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        origin_v.push_back(i+1);
    }
    
    if(v==origin_v) cout << -1 << '\n';
    else{
        prev_permutation(v.begin(), v.end());
        for(auto i : v) cout << i << ' ';
        cout << '\n';
    }
}
