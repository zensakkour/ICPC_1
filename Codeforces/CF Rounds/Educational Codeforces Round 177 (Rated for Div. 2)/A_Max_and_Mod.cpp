#include <bits/stdc++.h>
using namespace std;
using lli = long long;


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout <<"1\n";
            continue;
        }
        if (n % 2 == 0) {
            cout << "-1\n";
            continue;
        }
        vector<int> perm;
        perm.push_back(n);
        cout << n << " ";
        for (int i = 1; i < n; i++) {
            perm.push_back(i);
            cout << i << " ";
        }
        cout << "\n";
    }
}