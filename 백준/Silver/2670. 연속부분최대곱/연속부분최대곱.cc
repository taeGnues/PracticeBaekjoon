#include <bits/stdc++.h>

using namespace std;

int N;
double arr[10001], res;


int main(){
    
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){
        scanf("%lf", &arr[i]);
    }
    
    for(int i = 0 ; i < N ; i++){
        double tmp = 1l;
        for(int j = i ; j < N ; j++){
            tmp *= arr[j];
            res = max(res, tmp);
            
        }
    }
    
    printf("%0.3f\n", res);
    
}
