#include <bits/stdc++.h>


using namespace std;


int main(){
    ios::sync_with_stdio(0);

   int v1[100001] = {0};
   bool v2[2000001] = {0};

    int N=0, X=0, cnt=0;



    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> v1[i];
        v2[v1[i]] = true;
    }

    cin >> X;

    for(int i = 0 ; i < N ; i++){
        if(X>v1[i] && v2[X-v1[i]] && (X-v1[i])!=v1[i]) {v2[v1[i]] = false; cnt++;}

    }

    cout << cnt;

}
