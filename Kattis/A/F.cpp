#include <bits/stdc++.h>
using namespace std;

int minD;

void permute(vector<pair<int, int>>& b, int l, int r, int sx, int sy) {
    if (l == r) {
        int dist = 0;
        pair<int, int> cur = {sx, sy};
        for (const auto& p : b) {
            dist += abs(cur.first - p.first) + abs(cur.second - p.second);
            cur = p;
        }
        dist += abs(sx - cur.first) + abs(sy - cur.second);
        minD = min(minD, dist);
        return;
    }

    for (int i = l; i <= r; ++i) {
        swap(b[l], b[i]);
        permute(b, l + 1, r, sx, sy);
        swap(b[l], b[i]);  
    }
}

int main() {
    int t, w, h, sx, sy, n, x, y;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> b;
        cin >> w >> h >> sx >> sy >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            b.push_back({x, y});
        }

        minD = 1e9;
        permute(b, 0, n - 1, sx, sy);

        cout << minD << endl;
    }
}
