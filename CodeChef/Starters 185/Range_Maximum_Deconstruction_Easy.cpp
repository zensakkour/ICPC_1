#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'
#define loop(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)

const int MOD = 998244353;
const int INF = 1e18;

void solve(){
    int n; cin >> n;
    int m = n / 2;
    vi B(n+2);
    loop(i, 1,n+1) cin >> B[i];
    
    bool ok = true;
    loop(i, 1,m){
        if (B[i+1] < B[i]){ ok = false; break; }
    }
    loop(i,m+1, n){
        if (B[i+1] > B[i]){ ok = false; break; }
    }
    if (!ok){
        cout<< 0 << endl;
        return;
    }
    int ans= 1;
    loop(p,1, m){
        int a = B[p+1], b = B[m+p];
        int  low=min(a, b);
        bool E =(a > B[p]);
        bool F= (b> B[m+p+1]);
        if (E && F){
            if (a != b){ ans = 0; break; }
            ans =ans * (2*a - 1) % MOD;
        } else if(E){
            if (b< a){ ans = 0; break; }
            ans =ans * (2*a - 1) % MOD;
        } else if(F){
            if (a< b){ ans = 0; break; }
            ans = ans*(2*b-1)%MOD;
        } else{
            ans= ans*(1LL*low*low%MOD)%MOD;
        }
    }

    cout << ans << endl;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}