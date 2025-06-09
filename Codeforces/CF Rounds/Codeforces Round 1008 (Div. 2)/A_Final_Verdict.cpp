#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int t;cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        lli sm = 0;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
            sm += a[i];
        }
        string res = (sm == x*n) ? "YES\n" : "NO\n";
        cout << res;
    }
    return 0;
}