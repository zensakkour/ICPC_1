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
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_map<int,int> m{{0, 3},{1, 1},{2, 2},{3, 1},{5, 1}};
    
    int sm = 8;
    int i = 0;
    for(i = 0; i < n; i++){
        if(sm ==0){
            cout << i << endl;
            return;
        }
        if(m[a[i]]>0){
            sm--;
            m[a[i]]--;
        }
    } 
    cout << ( sm == 0 ? i : 0) << endl;

    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}