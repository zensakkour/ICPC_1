#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin >> t;
    while (t--) {
        string a, b, c;cin >> a >> b >> c;

        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)dp[i][0] = dp[i-1][0] + (c[i-1] != a[i-1]);

        for (int j = 1; j <= m; ++j)dp[0][j] = dp[0][j-1] + (c[j-1] != b[j-1]);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(dp[i-1][j] + (c[i+j-1] != a[i-1]),dp[i][j-1] + (c[i+j-1] != b[j-1]));
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}
