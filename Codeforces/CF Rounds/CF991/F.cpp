#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int sparse[MAXN][20];
int logTable[MAXN];

void ST(vector<int>& diff, int n) {
    for (int i = 0; i < n; i++) sparse[i][0] = diff[i];

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            sparse[i][j] = __gcd(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rangeGCD(int l, int r) {
    int j = logTable[r - l + 1];
    return __gcd(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}



int main() {
    logTable[1] = 0;
    for (int i = 2; i < MAXN; i++) 
        logTable[i] = logTable[i / 2] + 1;

    int t;cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            while (q--) {
            int l, r;
            cin >> l >> r;cout << "0 ";
            }
            cout << endl;
            continue;
        }

        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; i++) diff[i] = abs(a[i] - a[i + 1]);

        ST(diff, n - 1);

        while (q--) {
            int l, r;
            cin >> l >> r;l--; r--; 
            if (l == r)cout << "0 ";
            else cout << rangeGCD(l, r - 1) << " ";
        }
        cout << endl;
    }

    return 0;
}
