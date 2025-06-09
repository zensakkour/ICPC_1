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
    for(int i = 0; i < n; i++)cin >> a[i];
    vpii v;
    int cnt = 0;
    bool d = false;
    for(int i = n - 1; i > 0; i--){
        if(a[i] == 0){
            if(i == 1) d = true;
            cnt ++;
            v.pb({i, i + 1});
            i--;

        }

    }
    if(a[0] == 0){
        if(n - cnt == 1)goto done;
            if(d!= true){v.pb({1, 2});cnt++;}
    }
    v.pb({1, n - cnt});
    
    done :
    cout << sz(v) << endl;
    for(auto x : v){
        cout << x.F << " " << x.S << endl;
    }    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}