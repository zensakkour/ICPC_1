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

struct Seat { 
    int x, y, dist, table; 
};

void solve() {
    int n; 
    cin >> n;
    vector<int> t(n);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] == 0) ++zeros;
    }   

    struct Seat { int x, y, dist, table; };
    vector<Seat> cells;
    int g = (int)ceil( (sqrt(1 + 8.0*n) - 1) / 2.0 );
    int tables = g * g;
    cells.reserve(4LL * tables);
    vector<int> occ(tables, 0);

    auto mdist = [&](int x, int y) {
        return x + y + ((x%3==2 && y%3==2) ? 2 : 0);
    };

    int tid = 0;
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < g; ++j, ++tid) {
            int x0 = 3*i + 1, y0 = 3*j + 1;
            for (int dx = 0; dx <= 1; ++dx) {
                for (int dy = 0; dy <= 1; ++dy) {
                    int x = x0 + dx, y = y0 + dy;
                    cells.push_back({x, y, mdist(x,y), tid});
                }
            }
        }
    }

    sort(cells.begin(), cells.end(), [&](auto &A, auto &B) {
        if (A.dist != B.dist) return A.dist < B.dist;
        if (A.x    != B.x   ) return A.x    < B.x;
        return A.y < B.y;
    });

    int m = (int)cells.size();
    vector<char> used(m, 0);
    int ptr1 = 0, ptr0 = 0;

    for (int kind : t) {
        if (kind == 1) {
            while (used[ptr1]) ++ptr1;
            auto &s = cells[ptr1];
            cout << s.x << ' ' << s.y << '\n';
            used[ptr1] = 1;
            occ[s.table] += 1;
            ++ptr1;
        } else {
            while (used[ptr0] || occ[cells[ptr0].table] != 0) ++ptr0;
            auto &s = cells[ptr0];
            cout << s.x << ' ' << s.y << '\n';
            used[ptr0] = 1;
            occ[s.table] += 1;
            ++ptr0;
        }
    }
}



int32_t main() {
    int tc; 
    cin >> tc;
    while (tc--) solve();
    return 0;
}
