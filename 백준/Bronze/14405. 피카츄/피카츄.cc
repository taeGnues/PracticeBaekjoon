#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string tmp = "";
    cin >> tmp;
    
    string _tmp = "";
    for(int i = 0 ; i < tmp.length() ; i++){
        _tmp += tmp[i];
        if(_tmp == "pi") _tmp = "";
        else if(_tmp == "ka") _tmp = "";
        else if(_tmp == "chu") _tmp = "";
    }
    
    if(_tmp=="") cout << "YES";
    else cout << "NO";
    
}
