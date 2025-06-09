#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<set<int>> sets(n);
    deque<int> idx(n);
    iota(idx.begin(), idx.end(), 0); 
    vector<bool> alive(q + 2, false);
    int ans = 0;
    bool rev = false;

    for(int i = 1; i <= q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        int p = (c + ans - 1) % n;
        if(rev) p = n - 1 - p;
        int set_idx = idx[p];

        if(a == 1) {
            int r = (b + ans - 1) % n + 1;
            for(int j = 0; j < r; ++j) {
                int actual_idx = rev ? idx[n - 1 - j] : idx[j];
                sets[actual_idx].insert(i);
            }
            alive[i] = true;
        }
        else if(a == 2) {
            int r = (b + ans - 1) % n + 1;
            rev ^= true;
            if(r < n) {
                if(!rev) reverse(idx.begin(), idx.begin() + r);
                else reverse(idx.end() - r, idx.end());
            } else {
                rev ^= true; 
                reverse(idx.begin(), idx.end());
            }
        }
        else {
            int x = (b + ans - 1) % q + 1;
            if(alive[x]) {
                alive[x] = false;
                for(auto &s : sets) s.erase(x);
            }
        }

        if(sets[set_idx].empty()) ans = 0;
        else ans = *sets[set_idx].begin();

        cout << ans << '\n';
    }

    return 0;
}
