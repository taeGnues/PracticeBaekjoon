#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[2000];

int main() {
    int num,result=0,val;
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>arr[i];
    sort(arr,arr+num); // 투포인터를 위해 정렬

    for(int i=0;i<num;i++){
        val = arr[i];     // 찾고자 하는 번호
        int l=0,r=num-1,sum;
        while(l<r){
            sum = arr[l]+arr[r]; // 2개의 합 구하기.
            if(sum==val){  // 찾고자 하는 값과 같아질 때
                if(l!=i && r!=i){
                    result++;
                    break;
                }
                else if(l==i) l++;
                else if(r==i) r--;
            } 
            else if(sum<val) l++; // 찾고자 하는 값보다 작을때
            else r--; // 클 때
        }
    }
    cout<<result;
    return 0;
}

// 투포인터 (인터넷 참고)