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

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi a(n);
    loop(i, 0, n) cin>> a[i];
    int T = llabs(a[0]);
    int lc = 0;
    for (int i = 1; i < n; i++) {
        if (llabs(a[i]) < T)lc++;
        
    }

    if (lc <= n / 2) cout << "YES\n";
    else cout << "NO\n";
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
