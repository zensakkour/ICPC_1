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
#define ull unsigned long long

int f() {
    int n; cin >> n;
    vector<ull> a(n), b(n);
    loop(i, 0, n)cin >> a[i];
    loop(i, 0, n) cin >> b[i];
    string c; cin >> c;

    ull base = 0;
    loop(i, 0, n) base ^= a[i];

    ull vec[60] ={};
    int owner[60]; fill(owner, owner + 60, -1);

    for (int i = n - 1; i >= 0; --i) {
        ull d = a[i] ^ b[i];
        if (!d) continue;
        int o = (c[i] == '1');
        ull x = d;
        for (int bit = 59; bit >= 0; --bit) {
            if ((x >> bit) & 1) {
                if (vec[bit]) x ^= vec[bit];
                else {
                    vec[bit] =x;
                    owner[bit] = o;
                    break;
                }
            }
        }
    }

    ull ans = base;
    for (int bit = 59; bit >= 0;--bit) if (vec[bit]) {
        ull v = vec[bit];
        if (owner[bit]) {
            if ((ans ^ v) >ans) ans ^= v;
        } else {
            if ((ans ^ v) < ans) ans ^= v;
        }
    }
    return (long long)ans;
}

void solve() {
    int t; cin >>t;
    while (t--) cout << f() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
