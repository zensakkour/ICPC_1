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
    int n, k;cin >> n >> k;

    vi a(n);
    for (int &x : a)cin >> x;
    int cnt = 0;
    for (int x : a) {
        if (x <= k) 
            ++cnt;
    }

    if (cnt < 2) {
        cout << "NO\n";
        return;
    }

    vi s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + (a[i] <= k ? 1 : -1);
    }

    vector<char> pre(n + 1, 0), suf(n + 2, 0);
    for (int i= 1; i <= n; i++) {
        pre[i] = (s[i] >= 0);
        suf[i] = (s[n] - s[i - 1] >= 0);
    }

    vector<char> suf2(n + 3, 0);
    for (int i = n; i >= 1; i--) {
        suf2[i] = suf[i] | suf2[i + 1];
    }

    vi mx(n + 2, -INF);
    mx[n] = s[n];
    for (int i = n- 1; i >= 0; i--) {
        mx[i] = max(mx[i + 1], s[i]);
    }

    vector<char> midGood(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        midGood[i] =(mx[i] >= s[i - 1]);
    }

    vi mn(n + 1, INF);
    mn[0] = s[0];
    for (int i = 1; i <= n; i++) {
        mn[i] = min(mn[i - 1], s[i]);
    }

    vector<char> endGood(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        endGood[i] = (s[i] >= mn[i - 1]);
    }

    for (int l = 1; l <= n - 2; l++) {
        if (pre[l] && (suf2[l + 2] || midGood[l + 1])) {
            cout<< "YES\n";
            return;
        }
    }

    for (int r = 2; r <= n - 1; r++) {
        if (endGood[r] && suf[r + 1]) {
            cout << "YES\n";
            return;
        }
    }

    cout <<"NO\n";
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
