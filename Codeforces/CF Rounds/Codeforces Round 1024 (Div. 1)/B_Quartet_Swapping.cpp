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

bool invpar(vi &a) {
    int n = sz(a);
    if (n <= 1) return false;
    int m = n / 2;
    vi L(a.begin(), a.begin() + m), R(a.begin() + m, a.end());
    bool p = invpar(L) ^ invpar(R);

    int i = 0, j=0, k = 0, nl = sz(L), nr = sz(R);
    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++]= R[j++];
            if ((nl - i) & 1) p = !p;
        }
    }
    while (i < nl)a[k++] = L[i++];
    while (j < nr) a[k++] = R[j++];
    return p;
}

void solve() {
    int n; cin >> n;
    vi v(n);
    loop(i, 0, n) cin >> v[i];
    vi o, e;
    loop(i, 0, n) (i % 2 == 0 ? o.pb(v[i]) : e.pb(v[i]));
    vi so = o, se = e;
    sort(all(so)); sort(all(se));
    vi oc = o, ec = e;
    bool po = invpar(oc);
    bool pe = invpar(ec);
    bool I = po ^pe;

    vector<vi> c;
    if (!I) {
        loop(pi, 0, 2) {
            vi to = so, te = se;
            if (pi) {
                swap(to[sz(to)-1], to[sz(to)-2]);
                swap(te[sz(te)-1],te[sz(te)-2]);
            }
            vi r(n);
            int oi = 0, ei = 0;
            loop(i, 0, n) r[i] =(i%2 == 0 ? to[oi++] :te[ei++]);
            c.pb(r);
        }
    } else {
        {
            vi to = so, te = se;
            swap(te[sz(te)-1], te[sz(te)-2]);
            vi r(n);
            int oi = 0, ei = 0;
            loop(i, 0, n) r[i] = (i % 2 == 0 ? to[oi++]: te[ei++]);
            c.pb(r);
        }
        {
            vi to = so, te = se;
            swap(to[sz(to)-1], to[sz(to)-2]);
            vi r(n);
            int oi = 0, ei = 0;
            loop(i, 0, n) r[i] = (i % 2 == 0 ? to[oi++] : te[ei++]);
            c.pb(r);
        }
    }
    vi best = c[0];
    if (sz(c) > 1 && c[1] < best)best = c[1];
    loop(i, 0, n) cout <<best[i] << (i + 1 == n ? '\n' : ' ');
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
