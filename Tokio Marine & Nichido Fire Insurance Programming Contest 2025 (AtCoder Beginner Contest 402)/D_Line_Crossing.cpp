#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N, 0);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) % N]++;
    }
    int total = 1LL * M * (M - 1) / 2;
    int parallel = 0;
    for (int c : cnt) parallel += 1LL * c * (c - 1) / 2;
    cout << total - parallel << '\n';
}

int32_t main() {

    solve();
    return 0;
}
