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

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, x; cin >> n >> x;
    vi a;
    int tmp, res = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp < x)a.pb(tmp);
        else res++;
    }
    sort(all(a));
    int lim = 0;
    for(int i = sz(a) - 1; i >= 0; i--){
        lim++;
        if( lim * a[i] >= x){
            res++;
            lim = 0;
        }
    }
    cout << res << endl;

    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}