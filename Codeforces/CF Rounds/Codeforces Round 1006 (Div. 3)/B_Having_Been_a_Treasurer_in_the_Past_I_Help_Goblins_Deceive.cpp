#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        long long dCNT = 0, undCNT = 0;
        for(char c : s){
            if(c == '-') dCNT++;
            else undCNT++;
        }
        
        if(dCNT < 2){
            cout << 0 << "\n";
            continue;
        }
        
        long long ld = dCNT /2;    

        long long rd = dCNT -ld;    

        long long answer = undCNT * ld * rd;
        cout << answer << "\n";
    }
    
    return 0;
}
