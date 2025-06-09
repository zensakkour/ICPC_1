#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int trans = 0;
    for (int i = 1; i < n; i++) trans += (s[i] != s[i-1]);
    
    int flag = (s[0] == '1');
    int orig = n + trans + flag;

    vi p01, p10;
    for (int i = 1; i < n; i++) {
        if (s[i-1]=='0' && s[i]=='1') p01.pb(i);
        if (s[i-1]=='1' && s[i]=='0') p10.pb(i);
    }

    int best = 0;
    if (s[0]=='1') {
        for (int i : p01) {
            if (i >= 2) {
                best = 2;
                break;
            }
        }
    }
    if (best < 2) {
        if (sz(p01) > 1 && p01.back() - p01.front()>= 2) best = 2;
        if (sz(p10) > 1 && p10.back()- p10.front() >= 2) best = 2;
    }
    if (best < 2) {
        if (s[0]=='1' && s[n-1]=='0')
            best = max(best, 1LL);
    }
    if (best <1) {
        if (s[n-1] =='0' && !p01.empty())
            best = 1;
        if (s[n-1]=='1' &&  !p10.empty())
            best = 1;
    }

    cout << (orig- best)<< endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
