#include<bits/stdc++.h>
using namespace std;

int op[110], A[15], B[15], N;
int ans_mx=INT_MIN, ans_min=INT_MAX;

int cal(int n1, int oper, int n2){
    int res=0;
    
    if(oper==1){
        res = n1 + n2;
    }else if(oper==2){
        res = n1 - n2;
    }else if(oper==3){
        res = n1 * n2;
    }else if(oper==4){
        res = n1 / n2;
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    
    int now=0;
    for(int i = 1 ; i < 5 ; i++){ // 1 + 2 - 3 x 4 % 를 의미함.
        int tmp=0;
        cin >> tmp;
        for(int j = now ; j < now+tmp ; j++){
            op[j]=i;
        }
        now += tmp;
    } // 연산자 순서 설정.
    

    do{
        memcpy(B, A, sizeof(A)); // 배열 복사. A를 B에 담음.
        for(int i=0 ; i < N-1 ; i++) {
            
//            cout << B[i] << ' ' << op[i] << ' ' << B[i+1]; test 용
            B[i+1] = cal(B[i], op[i], B[i+1]); // cal 값을 그다음 값으로 넘겨줌.
//            cout << '=' << B[i+1] << '\n';
            
        }
        ans_mx = max(ans_mx, B[N-1]); // 정답1 구하기
        ans_min = min(ans_min, B[N-1]); // 정답2 구하기
        
        
    }while(next_permutation(op, op + N-1));
    
    cout << ans_mx << '\n' << ans_min << '\n';
    
}
