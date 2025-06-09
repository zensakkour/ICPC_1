#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                                  
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;   string s;
        cin >> n >> s;

        vector<int> pos;                    
        for (int i = 0; i < n; ++i)
            if (s[i] == 'B') pos.push_back(i);

        if (pos.empty() || (int)pos.size() == n) { 
            cout << 0 << '\n';
            continue;
        }

        int k = (int)pos.size();
        int64 base  = 0;                   
        int  oddCnt = 0;                   
        int  oddParity[2] = {0, 0};       

        for (int i = 0; i < k; ++i) {
            int d = pos[i] - i;
            base += d / 2;
            if (d & 1) {                     
                ++oddCnt;
                ++oddParity[i & 1];
            }
        }

        int64 extra = oddCnt - min(oddParity[0], oddParity[1]);
        cout << base + extra << '\n';
    }
    return 0;
}
