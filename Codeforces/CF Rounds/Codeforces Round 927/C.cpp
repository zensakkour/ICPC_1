#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string s;
        cin >> s;

        long long product = 1;
        vector<int> remainder(n);
        int l=0,r=n-1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                product = (product * a[l]) % m;
                l++;
            } else {
                product = (product * a[n - i - 1]) % m;
            }

            remainder[i] = product;
        }

        for (int i = 0; i < n; i++) {
            cout << remainder[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
