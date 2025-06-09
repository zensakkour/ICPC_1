#include <bits/stdc++.h>

using namespace std;

int BL(int i, int time, const vector<int>& t, const vector<int>& z, const vector<int>& y) {
    int period = t[i] * z[i] + y[i];
    return time / period * z[i] + min((time % period) / t[i], z[i]);
}

bool canBlow(int time, int m, int n, const vector<int>& t, const vector<int>& z, const vector<int>& y) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += BL(i, time, t, z, y); 
        if (cnt >= m) {
            return true;
        }
    }
    return false;
}

int main() {
    int m, n; cin >> m >> n;
    
    vector<int> t(n), z(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }

    int lo = -1, hi = m * 300;  
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (canBlow(mid, m, n, t, z, y)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << endl;  

    int remaining = m;
    for (int i = 0; i < n; i++) {
        auto num = BL(i, hi, t, z, y);
        if (num > remaining) {
            num = remaining;
        }
        remaining -= num;
        cout << num << " ";  
    }
    cout << endl;

    return 0;
}
