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
    int n; cin >> n;
    vi a(n+2,0);
    a[0] = - INF;
    int id = 1;
    for (int i = 0; i < n; i++){
        int x; 
        cin >> x;
        if(a[id - 1] != x){
            a[id] = x;
            id++;
        }
    }
    a[id] = -INF;
    
    int ans = 0;
    for(int i= 1; i < id ; i++){ 
        if (a[i - 1]< a[i] && a[i] > a[i + 1]) ans++;
    }
    cout << ans << endl;
    
}


int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

}
