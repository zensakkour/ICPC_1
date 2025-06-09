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

void solve() {
    int n, m; cin >> n >> m;
    vi init(n);
    loop(i, 0, n) {
        cin >> init[i];
    }

    int fullMask = (1 << n) - 1;
    vi dp(1 << n);
    loop(mask,0, 1 << n) {
        int sum =0;
        loop(i, 0, n) {
            if (mask&(1 << i)) sum += init[i];
        }
        dp[mask] = sum;
    }

    int extSize =1 << (n + 2);
    vi x(extSize),y(extSize);

    loop(day, 0, m) {
        vi a(n + 2), b(n + 2), c(n + 2);
        
        loop(i, 1, n+1) cin >> a[i];
        
        a[0] = a[n]; a[n+1] = a[1];
        
        loop(i, 1, n+1) cin >> b[i];
        
        b[0] = b[n]; b[n+1] = b[1];
        
        loop(i, 1, n+1) cin >> c[i];

        c[0] = c[n]; c[n+1] = c[1];

        vi nextDP(1 << n, INF);
        fill(all(x), INF);

        loop(mask, 0, 1 << n) {
            int ext = ((mask >> (n - 1)) & 1)  | (mask << 1) | ((mask & 1) <<(n+1));
            ext &=extSize - 1;
            x[ext] = dp[mask];
        }

        loop(pos, 0, n) {
            fill(all(y), INF);
            int bit0= 1 << pos;
            int bit1= 1<< (pos + 1);
            int bit2= 1<< (pos + 2);

            loop(m2, 0, extSize) {
                int cur = x[m2];
                if (cur == INF) continue;

                int offMask= m2 & ~bit0;
                y[offMask]= min(y[offMask], cur);

                int onMask = m2 | bit0;
                int val = cur;
                if(!(m2 & bit0))val+= c[pos];
                if (!(m2 & bit1))val+= b[pos + 1];
                if (!(m2 & bit2))val+= a[pos + 2];
                y[onMask] = min(y[onMask], val);
            }
            x.swap(y);
        }

        loop(m2, 0,extSize) {
            int base = m2 & fullMask;
            nextDP[base]= min(nextDP[base], x[m2]);
        }

        dp.swap(nextDP);
        cout <<dp[fullMask] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
