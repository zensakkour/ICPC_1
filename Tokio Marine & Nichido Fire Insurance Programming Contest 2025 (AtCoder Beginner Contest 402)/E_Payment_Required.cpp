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

int n, X;
vector<vector<double>> dp;
vector<vector<int>> v;

double dfs(int mask, int rem) {
    if (rem == 0) return 0.0;
    if (dp[mask][rem] > -0.5)return dp[mask][rem];

    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1<<i)) continue;
        int c = v[i][1];
        if (c > rem) continue;      
        double p = v[i][2] / 100.0;
        double s = v[i][0];
        int nxt = mask |(1<<i);

        double take = p * (s + dfs(nxt, rem - c)) + (1 - p) *dfs(mask, rem - c);
        ans = max(ans, take);
    }

    return dp[mask][rem] = ans;
}

void solve() {
    cin >> n >> X;
    v.assign(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> v[i][0]>> v[i][1] >> v[i][2];

    dp.assign(1<<n, vector<double>(X+1, -1.0));
    for (int mask = 0; mask < (1<<n); mask++)
        dp[mask][0] = 0.0;

    cout << fixed << setprecision(10)
         << dfs(0, X) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}
