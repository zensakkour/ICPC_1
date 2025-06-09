#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : c) cin >> x;

    vector<int> b(n, 0);
    vector<bool> used(n + 1, false);
    bool possible = true;

    // Check fixed positions in c for validity
    for (int i = 0; i < n; ++i) {
        if (c[i] != 0) {
            if (used[c[i]] || find(a.begin(), a.end(), c[i]) == a.end()) {
                possible = false;
            }
            used[c[i]] = true;
            b[i] = c[i];
        }
    }
    if (!possible) {
        cout << -1 << '\n';
        return;
    }

    // Collect remaining elements and sort them
    vector<int> remaining;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            remaining.push_back(i);
        }
    }
    sort(remaining.begin(), remaining.end());

    // Fill zeros in sorted order
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == 0) {
            if (ptr < remaining.size()) {
                b[i] = remaining[ptr++];
            } else {
                possible = false;
                break;
            }
        }
    }
    if (!possible) {
        cout << -1 << '\n';
        return;
    }

    // Check if b is a permutation
    vector<int> check = b;
    sort(check.begin(), check.end());
    for (int i = 0; i < n; ++i) {
        if (check[i] != i + 1) {
            possible = false;
            break;
        }
    }
    if (!possible) {
        cout << -1 << '\n';
        return;
    }

    // Validate if b can be obtained from a via the operations
    vector<int> pos_a(n + 1), pos_b(n + 1);
    for (int i = 0; i < n; ++i) {
        pos_a[a[i]] = i;
        pos_b[b[i]] = i;
    }

    for (int x = 1; x <= n; ++x) {
        int target_pos = pos_b[x];
        int original_pos = pos_a[x];
        if (target_pos < original_pos) {
            int mn = a[target_pos];
            for (int i = target_pos; i <= original_pos; ++i) {
                mn = min(mn, a[i]);
            }
            if (mn != x) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        for (int num : b) {
            cout << num << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}