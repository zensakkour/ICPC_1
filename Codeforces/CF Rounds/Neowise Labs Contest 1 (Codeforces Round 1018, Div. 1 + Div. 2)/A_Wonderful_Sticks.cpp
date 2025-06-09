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
    int n;
    string s;
    cin >> n >> s;
    int rem = 0;
    for (char c : s) if (c == '<') rem++;
    vi ans(n+1);
    ans[1] = rem + 1;
    int cur_min = ans[1], cur_max = ans[1];
    set<int> avail;
    for (int x = 1; x <= n; x++) if (x != ans[1]) avail.insert(x);
    for (int i = 2; i <= n; i++) {
        if (s[i-2] == '<') {
            auto it = avail.lower_bound(cur_min);
            --it;


            
            ans[i] = *it;
            cur_min = ans[i];
            avail.erase(it);
        } else {
            auto it = avail.upper_bound(cur_max);
            ans[i] = *it;
            cur_max = ans[i];
            avail.erase(it);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
