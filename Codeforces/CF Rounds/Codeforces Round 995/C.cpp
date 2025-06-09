#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3 * 1e5;

int main() {
    int t;cin >> t;
    while (t--) {
        int n, m, k;cin >> n >> m >> k;
        vector<int> a(m);  
        for (int i = 0; i < m; i++) cin >> a[i];

        vector<int> q(k); 
        vector<bool> known(n + 1, false);  
        for (int i = 0; i < k; i++) {
            cin >> q[i];
            known[q[i]] = true; 
        }
        for (int i = 0; i < m; i++) {
            if (k== n || (k== n - 1 && !known[a[i]]))cout << "1";
            else cout << "0";
        }
        cout << endl;
    }return 0;
}