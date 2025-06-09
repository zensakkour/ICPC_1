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
    vi p(2*n,-1);
    vi seen(2*n,-1);

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            p[i + j] = x;
        }
    }

    for(int i = 0; i < 2*n - 1; i++) seen[p[i]-1] = 1;
    
    for(int i = 0; i < 2*n ; i++){
        if(seen[i]==-1){
            cout << i+1 << " ";
            break;
        }
    }
    for(int k = 0; k < 2*n - 1; k++){
        cout << p[k] << (k == 2*n - 2 ? '\n' : ' ');
    }

}


int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}