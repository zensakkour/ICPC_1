#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string n;cin >> n;

        int digit_sum = 0,cnt2 = 0, cnt3 = 0;
        for (char c : n) {
            int digit = c - '0';
            digit_sum += digit;
            if (digit == 2) cnt2++;
            if (digit == 3) cnt3++;
        }

        bool possible = false;
        
        
        for (int i = 0; i <= cnt2; i++) { 
            for (int j = 0; j <= cnt3; j++) { 
                if ((digit_sum + i * 2 + j * 6) % 9 == 0) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}