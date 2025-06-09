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

void toggle(unordered_set<int>& st, int x) {
    if (st.find(x) == st.end()) st.insert(x);
    else st.erase(x);
}

void solve() {
    int n;
    cin >> n;
    unordered_set<int> oddCol, oddDiag;
    oddCol.reserve(n * 2);
    oddDiag.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >>x >> y;
        toggle(oddCol, x);
        toggle(oddDiag, x + y);
    }
    int s =*oddCol.begin();
    int d =*oddDiag.begin();
    int t= d - s;
    cout << s << " " << t << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
