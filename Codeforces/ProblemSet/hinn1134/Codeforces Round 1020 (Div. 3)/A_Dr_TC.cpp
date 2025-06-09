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
    int cnt = 0;
    for(auto c : s){
        if(c == '1')cnt++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='0')ans += (cnt + 1);
        else ans += (cnt - 1);
    }
    cout << ans << endl;
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}