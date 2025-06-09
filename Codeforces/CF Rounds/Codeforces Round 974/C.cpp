#include <bits/stdc++.h>
using namespace std;
#define lli long long

bool canMakeUnhappy(const vector<lli>& a, lli n, lli x, double sum, lli idmax) {
    double newSum = sum + x;
    double threshold = newSum / n / 2; 
    lli unhappyCount = 0;

    for (int i = 0; i < n; i++) {
        if (i == idmax && a[i] + x < threshold) {
            unhappyCount++;
        } else if (i != idmax && a[i] < threshold) {
            unhappyCount++;
        }
    }
    return unhappyCount > (n / 2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;

        vector<lli> a(n);
        double sum = 0;
        lli maxWealth = 0, idmax = -1;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] > maxWealth) {
                maxWealth = a[i];
                idmax = i;
            }
        }

        if (n < 3) {
            cout << "-1\n"; 
            continue;
        }

        lli low = -1, high = 1e12, ans = -1;

        while (low + 1< high) {
            lli mid = low + (high - low) / 2;
            if (canMakeUnhappy(a, n, mid, sum, idmax)) {
                ans = mid;
                high = mid; 
            } else {
                low = mid; 
            }
        }

        cout << (ans == -1 ? -1 : ans) << endl;
    }
    return 0;
}
