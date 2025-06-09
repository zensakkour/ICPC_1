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
    int n; cin >> n;
    vector<vi> g(n, vi(n, -1));

    int x = (n - 1) / 2;
    int y = (n - 1) / 2;

    int dx[4] = {0, 1, 0, -1};   
    int dy[4] = {1, 0, -1, 0};
    int dir = 0;                     
    int cur = 0;                      
    g[x][y] = cur++;                  

    for (int step = 1; cur < n*n; step++) {
        for (int rep = 0; rep < 2 && cur < n * n; rep++) {
            for (int k = 0; k < step && cur <n*n; k++) {
                x += dx[dir];
                y+= dy[dir];

                if (0 <= x && x < n && 0 <= y && y < n && g[x][y] == -1)
                    g[x][y] = cur++;
            }
            dir = (dir + 1) & 3;       
        }
    }

    loop(i, 0,n) {
        loop(j, 0, n) cout << g[i][j] << (j + 1 == n ? '\n' : ' ');
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
