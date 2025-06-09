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

int solve_chain(int n, const vector<int>& cost, const vector<int>& mask) {
    vector<array<int,2>> dp(n+1, {INF, INF});
    dp[1][0] = 0;
    dp[1][1] = cost[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
        for (int u = 0; u <2; u++) {
            for (int v = 0; v < 2; v++) {
                int bit = (u<<1) | v;
                if (mask[i-1] & (1<<bit)) {
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + (v ? cost[i] : 0));
                }
            }
        }
    }
    return min(dp[n][0],dp[n][1]);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> h(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> h[i][j];
        }
    }
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];

    vector<int> mask_rows(n+1, (1<<4)-1), mask_cols(n+1, (1<<4)-1);

    for (int i = 1; i < n; i++) {
        int m = (1<<4)-1;
        for (int j = 1; j <= n; j++) {
            int d = h[i][j] - h[i+1][j];
            int m2 = 0;
            if (d == 0)  m2 = (1<<1)|(1<<2);
            else if (d == 1) m2 = ((1<<4)-1) & ~(1<<1);
            else if (d == -1)m2 = ((1<<4)-1) & ~(1<<2);
            else   m2 = (1<<4)-1;
            m &= m2;
        }
        mask_rows[i] = m;
    }
    for (int j = 1; j < n; j++) {
        int m = (1<<4)-1;
        for (int i = 1; i <= n; i++) {
            int d = h[i][j] - h[i][j+1];
            int m2 = 0;
            if (d == 0) m2 = (1<<1)|(1<<2);
            else if (d == 1) m2 = ((1<<4)-1) & ~(1<<1);
            else if (d == -1)m2 = ((1<<4)-1) & ~(1<<2);
            else m2 = (1<<4)-1;
            m &= m2;
        }
        mask_cols[j] = m;
    }

    int cost_rows = solve_chain(n, a, mask_rows);
    int cost_cols = solve_chain(n, b, mask_cols);
    if (cost_rows >= INF || cost_cols >= INF) {
        cout << -1 << endl;
    } else {
        cout << cost_rows+ cost_cols << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
    return 0;
}
