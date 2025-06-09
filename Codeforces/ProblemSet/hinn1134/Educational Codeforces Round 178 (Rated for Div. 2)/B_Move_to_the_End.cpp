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
    vi a(n), m(n,0);
    int mx = -1;
    loop(i, 0, n){
        cin >> a[i];
        mx = max(mx, a[i]);
        m[i] = mx;
    }

    int sm = 0;
    int tmp = 0;
    loop(i, 0, n){
        tmp = sm;
        sm += a[n-1-i];
        cout << max(sm,tmp + m[n-1-i] )<< " ";
    }
    cout << endl;

    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}