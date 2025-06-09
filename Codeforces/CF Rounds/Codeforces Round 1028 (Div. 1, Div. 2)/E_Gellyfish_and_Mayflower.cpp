#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define loop(i,a,b) for (int i = (a), _b = (b); i < _b; ++i)

const int CMAX = 200;                          
const int LIM = CMAX * CMAX + CMAX - 1;      
const int TBL = LIM + CMAX;                  
const long long NEG = -(1LL << 60);

void solve() {
    int n, m;  cin >> n >> m;

    vector<int>  cost(n +1);
    vector<int>  power(n + 1);
    loop(i, 1, n + 1) cin >> cost[i] >> power[i];

    vector<vector<int>> g(n + 1);
    loop(e, 0, m) {
        int u, v; cin >>u >> v;
        g[u].push_back(v);                    
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(TBL + 1, NEG));
    vector<int> bestC(n + 1);               
    vector<int> bestP(n + 1);               

    dp[1].assign(TBL + 1, 0);
    bestC[1] =cost[1];
    bestP[1] = power[1];

    for (int v= 1; v <= n; ++v) {
        int c = cost[v];
        int w =power[v];
        for (int x = c; x <= TBL; ++x)
            if (dp[v][x- c] != NEG)                    
                dp[v][x]= max(dp[v][x], dp[v][x - c] + w);

        if (bestC[v] == 0 ||
            1LL * w *bestC[v] > 1LL * bestP[v] * c ||
           (1LL * w* bestC[v] == 1LL * bestP[v] * c && c < bestC[v])) {
            bestC[v] = c;
            bestP[v]= w;
        }

        for (int u :g[v]) {
            for (int x = 0; x <= TBL; ++x)
                if (dp[v][x] > dp[u][x]) dp[u][x] = dp[v][x];

            if (bestC[u] == 0 ||
                1LL* bestP[v] * bestC[u] > 1LL * bestP[u] * bestC[v] ||
               (1LL * bestP[v] * bestC[u] == 1LL * bestP[u] * bestC[v] &&
                bestC[v] < bestC[u])) {
                bestC[u] = bestC[v];
                bestP[u] = bestP[v];
            }
        }
    }

    for (int v = 1; v <= n; ++v)
        for (int x = 1; x <= TBL; ++x)
            dp[v][x] = max(dp[v][x], dp[v][x - 1]);

    int Q;  cin >> Q;
    while (Q--){
        int p; long long r; cin >> p >> r;
        if (r <= TBL) {
            cout << dp[p][r] << '\n';
        } else {
            long long bc= bestC[p], bp = bestP[p];
            long long t   = (r - TBL) / bc;
            long long rem = r - t * bc;
            cout << t * bp + dp[p][rem] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
