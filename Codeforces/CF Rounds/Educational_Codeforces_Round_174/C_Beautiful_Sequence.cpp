#include <bits/stdc++.h>
using namespace std;
using lli = long long;
lli mod = 998244353;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n,0);
        for(int i = 0;i < n;i++) cin >> a[i];

        lli dp1 = 0, dp2 = 0, dp3 = 0;

        for(int i = 0;i < n;i++){
            if(a[i] == 1){
                dp1 = (dp1 + 1)%mod;
            }
            if(a[i] == 2){
                dp2 = (dp2 * 2 + dp1)%mod;
            }
            if(a[i] == 3){
                dp3 = (dp3 + dp2)%mod;
            }
        }
        cout << dp3 % mod << endl;
    }
    

}