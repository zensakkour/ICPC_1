#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                int j = i;
                while (j < s.size() && s[j] == '1') j++;
                ans += j - i;
                i = j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}