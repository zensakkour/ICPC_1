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
    int n, k;
    cin >> n >> k;
    vi l(n), r(n), mx(n), mn(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    int total_max = 0;
    for (int i = 0; i < n; i++) {
        mx[i] = max(l[i], r[i]);
        mn[i] = min(l[i], r[i]);
        total_max += mx[i];
    }
    sort(mn.rbegin(), mn.rend());
    int take = 0;
    for (int i = 0; i < k - 1; i++) {
        take += mn[i];
    }
    cout << total_max + take + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
