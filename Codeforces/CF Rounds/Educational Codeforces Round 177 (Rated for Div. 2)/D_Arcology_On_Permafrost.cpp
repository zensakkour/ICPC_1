#include <bits/stdc++.h>
using namespace std;
using lli = long long;


int main(){

    int t;cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int cand1 = n/ (m + 1);             
        int cand2= (n- k) / m;               
        int X = min(cand1, cand2);
        int S =  max(k,X);
        vector<int> ans(n+1, X);
        bool ok =true;
        
        for (int x =0; x< X; x++){
            for (int j= 0; j <= m; j++){
                int pos= x + 1 + j * S;
                if(pos> n){
                    ok = false; 
                    break;
                }
                ans[pos ] = x;
            }
            if(!ok) break;
        }
        for (int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}