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
    int n, x; cin >> n >> x;
    if(n == 1){
        cout << "0\n";
        return;
    }
    vi cells(n,0);
    cells[n-1] = min(x, n-1);
    int z = 0;
    for(int i = 0; i < n-1; i++){
        if(z==x)z++;
        cells[i] = z;z++;
    }
    for(int i = 0; i < n; i++){
        cout << cells[i] << " ";
    }
    cout << endl;
    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}