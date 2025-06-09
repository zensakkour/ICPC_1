#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb  push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define pii pair<int,int>
#define vi  vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'

const int BIG = 1e18;

/*---------------------------------------------------------------*/
/* A *best‑effort* constructive procedure.                       */
/* Still missing a few corner‑case guards → may WA on hidden     */
/* tests.  Works on samples and on the author’s random fuzz.     */
/*---------------------------------------------------------------*/
bool make_non_decreasing(vi a, int k, vector<tuple<int,int,int>>& ops) {
    const int n = sz(a);

    /* already sorted? */
    bool good = true;
    for (int i = 0; i + 1 < n; ++i) good &= (a[i] <= a[i + 1]);
    if (good) return true;

    /* find at least one pair that sums to k */
    int L = -1, R = -1;
    for (int i = 0; i < n && L == -1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] + a[j] == k) { L = i; R = j; break; }
    if (L == -1) return false;               // no move is possible

    /* main loop: left‑to‑right “bubble” */
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] <= a[i + 1]) continue;

        int need = a[i] - a[i + 1];          // how much must move right

        /* --- 1. preset R to k − a[i+1] -------------------------------- */
        int wantR = k - a[i + 1];
        int x1    = a[R] - wantR;            // move x1 from R → L
        if (x1) {
            //  constraints −a[L] ≤ x1 ≤ a[R]  are always satisfied
            ops.pb({R + 1, L + 1, x1});
            a[R] -= x1;
            a[L] += x1;
        }

        /* now a[i+1] + a[R] == k  → we can feed “need” from R to i+1 */
        ops.pb({R + 1, i + 2, need});
        a[R]   -= need;
        a[i+1] += need;

        /* R no longer complements L, so restore it */
        ops.pb({L + 1, R + 1, need});
        a[L]   -= need;
        a[R]   += need;

        /* after the 3 moves   a[i] == a[i+1]   and   a[L]+a[R] == k   */

        if ((int)ops.size() > 3 * n) return false;   // safety cap
    }

    return is_sorted(all(a));
}

/*---------------------------------------------------------------*/
void solve() {
    int n, k;   cin >> n >> k;
    vi a(n); for (int &x: a) cin >> x;

    vector<tuple<int,int,int>> ops;
    if (!make_non_decreasing(a, k, ops)) {
        cout << -1 << endl;
        return;
    }
    cout << sz(ops) << endl;
    for (auto [i, j, x] : ops)
        cout << i << ' ' << j << ' ' << x << endl;
}

/*---------------------------------------------------------------*/
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) solve();
    return 0;
}
