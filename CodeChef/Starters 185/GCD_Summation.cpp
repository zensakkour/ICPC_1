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

void solve(){
    int n, K; cin >> n >> K;
    if (K<n- 1) {
        cout <<-1 << endl;
        return;
    }
    int g = K-(n - 2);
    cout << g<<' '<<2 * g;
    if (n>2) {
        int L = 2 * g + 1;  
        loop(i, 3,n+1) {
            cout << ' '<< (L +(i-3));
        }
    }
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}