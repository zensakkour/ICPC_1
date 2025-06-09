#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> seg(a.begin() + l - 1, a.begin() + r);
        sort(seg.begin(), seg.end());
        
        long long mins = 0;
        for (itn i=0; i<r-l+1 ; i++) {
            mins += seg[]
        }
        cout << mins << '\n';
    }
}

int main() {
    solve();
    return 0;
}
