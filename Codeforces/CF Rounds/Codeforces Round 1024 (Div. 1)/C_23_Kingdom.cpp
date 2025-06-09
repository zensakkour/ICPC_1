#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) {
        int n;  cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        int lo = 0, hi = n / 2;

        auto ok = [&](int K) -> bool {
            if (K == 0) return true;

            vector<int> pre(K), suf(K);
            for (int i = 0; i < K; ++i) {
                pre[i] = a[1 + i];             
                suf[i] = a[n - K + 1 + i];     
            }
            sort(pre.begin(), pre.end());
            sort(suf.begin(), suf.end());

            for (int i = 0; i < K; ++i) {
                int need = i + 1;              
                if (pre[i] < need || suf[i] < need) return false;
            }
            return true;
        };

        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            (ok(mid) ? lo : hi) = mid;
        }

        int K = lo;
        cout << K * (n - K) << '\n';
    }
    return 0;
}
