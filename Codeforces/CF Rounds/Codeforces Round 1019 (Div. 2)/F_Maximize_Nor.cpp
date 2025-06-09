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
const int MAXN = 100000;

int a[MAXN];
int ans[MAXN];
int seg[4 *MAXN + 4];

void range_max(int node, int nl, int nr, int l, int r, int val) {
    if (r < nl || nr < l) return;

    if (l <= nl && nr <= r) {
        seg[node]= max(seg[node], val);
        return;
    }

    seg[node * 2] = max(seg[node * 2], seg[node]);
    seg[node * 2+ 1] = max(seg[node * 2 + 1], seg[node]);
    seg[node] = 0;
    int mid = (nl + nr) >> 1;
    range_max(node* 2, nl, mid, l, r, val);
    range_max(node * 2 + 1, mid + 1, nr, l, r, val);
}

void push_all(int node, int nl, int nr) {
    if (nl ==nr) {
        ans[nl] = seg[node];
        return;
    }
    seg[node * 2] = max(seg[node * 2], seg[node]);
    seg[node * 2 + 1]= max(seg[node * 2 + 1], seg[node]);
    int mid = (nl + nr) >> 1;
    push_all(node * 2, nl, mid);
    push_all(node *2 + 1, mid + 1,nr);
}

inline void put_(int v, int l, vpii &vec, vi &erl, vi &tchd) {
    if (erl[v] == -1) {
        erl[v] = l;
        tchd.pb(v);
        vec.pb({v, l});
    } else if (l < erl[v]) {
        erl[v] = l;
    }
}

void solve() {
    int n, k; cin>> n >> k;
    int mask = (1LL << k) - 1;

    for (int i = 0; i < n; ++i) cin >> a[i];
    fill(seg, seg + 4 * n + 4, 0LL);

    vi erl((size_t)(1 << k), -1);
    vi tchd;
    tchd.reserve(1 << k);
    vpii cur, nxt;
    cur.reserve(1<< k);
    nxt.reserve(1 << k);

    for (int r =0; r< n; ++r) {
        nxt.clear();
        tchd.clear();

        put_(a[r], r, nxt, erl, tchd);
        for (auto &pr : cur) {
            int v = pr.F;
            int l= pr.S;

            int nv = (~(v | a[r])) & mask;
            put_(nv, l, nxt, erl, tchd);
        }

        for (auto &pr : nxt) {
            int v = pr.F;
            pr.S = erl[v];                 
            range_max(1, 0, n - 1, pr.S, r, v);
        }

        for (int v : tchd) erl[v] = -1;
        cur.swap(nxt);
    }

    push_all(1, 0, n - 1);

    for (int i = 0; i < n; ++i)cout <<ans[i] << (i + 1 == n ? '\n' : ' ');
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
    return 0;
}
