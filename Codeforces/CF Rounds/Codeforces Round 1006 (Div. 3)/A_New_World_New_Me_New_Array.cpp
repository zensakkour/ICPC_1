#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){

    int t; cin >> t;
    while(t--){
        int n, p, m;
        int k; cin >> n >> k >> p;
        
        if(k == 0){
            cout << 0 << "\n";
            continue;
        }
        
        if(k > n * p || k < -n * p){
            cout << -1 << "\n";
            continue;
        }
        
  
        int ops = (abs(k) + p - 1) / p; 

        if(ops <= n) cout << ops << "\n";
        else cout << -1 << "\n";
    }
    
    return 0;
}
