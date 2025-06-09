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
#define loop(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, x;cin >> n >> x;
    if (n == 1) {
        cout << (x ? x : -1) << endl;
        return;
    }

    if (n == 2) {
        if (x == 0) {               
            
            cout << 2 << endl;
        } else if (x== 1) {        
            cout << 5 << endl;
        } else if ((x & (x -1)) == 0) { 
            cout << x + 2 << endl;
        } else { 

            cout <<x << endl;
        }
        return;
    }

    if (x == 0) {
        cout << (n % 2 == 0 ? n : n + 3) << endl;
        return;
    }
    if (x == 1) {
        cout << (n % 2? n : n + 3) << endl;
        return;
    }

    int bits = __builtin_popcountll(x);
    int gap  = n -bits;            

    if (gap >= 0) {
        cout << x +(gap % 2 == 0 ? gap : gap + 1) << endl;
    } else {
        cout << x <<endl;         
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
