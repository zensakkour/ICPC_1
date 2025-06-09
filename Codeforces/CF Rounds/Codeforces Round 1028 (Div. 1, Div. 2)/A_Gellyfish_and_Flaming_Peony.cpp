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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >>t;
    const int M = 5000;


    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int g = 0;
        loop(i,0,n){ cin>> a[i]; g = gcd(g, a[i]); }
        int k = 0;
        loop(i,0,n) if (a[i] == g) ++k;
        if (k) { cout <<n - k << '\n'; continue; }
        vector<int> dp(M +1, 1e9), ndp;
        loop(i,0,n) {
            int x = a[i] /g;
            ndp = dp;
            ndp[x] =1;
            loop(v,1,M+1) if (dp[v] < 1e9) {
                int y = gcd(v, x);
                if (ndp[y] > dp[v] + 1) ndp[y] = dp[v] + 1;
            }
            dp.swap(ndp);
        }
        cout << n + dp[1] - 2 << '\n';
    }
    return 0;
}
