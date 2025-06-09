#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int BIG = 60;

void build(const vi &idx, int k , int &low, int &high, const vi &rnd, vi &perm) {
    if (sz(idx) == 1) {
        perm[idx[0]] = low;
        return;
    }
    vi nxt;
    const int m = sz(idx);

    for (int i = 0;i < m;) {
        if (rnd[idx[i]] != k) {
            nxt.pb(idx[i]);
            ++i;
            continue;
        }

        int j = i;
        while (j < m && rnd[idx[j]] == k) ++j;
        int len = j - i;

        bool leftEdge= (i == 0);
        bool rightEdge = (j == m);

        vi val(len);
        if (k & 1) {
            for (int t= 0; t < len; ++t)
                val[t] = high - t;
            high -= len;
            if (!leftEdge)
                reverse(all(val));
        } else {
            for (int t = 0; t < len; ++t)
                val[t] = low + t;
            low += len;
            if (rightEdge)
                reverse(all(val));
        }

        for (int t = 0; t < len; ++t)
            perm[idx[i + t]] = val[t];

        i = j;
    }

    build(nxt, k + 1, low, high,rnd, perm);
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int &x : a) {
        cin >> x;
        if (x == -1) x = BIG;
    }

    vi perm(n);
    vi all_idx(n);
    iota(all_idx.begin(), all_idx.end(), 0);

    int low = 1, high = n;
    build(all_idx, 1,low, high, a, perm);

    for (int i = 0; i < n; ++i)
        cout << perm[i] <<(i + 1 == n ? '\n' : ' ');
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
    return 0;
}
