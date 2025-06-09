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
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    loop(i,0,n){
        cin >> a[i];
    }
    loop(i,0,n){
        cin >> b[i];
    }
    int c = -1;
    loop(i,0,n){
        if(b[i] != -1){
            c = a[i] + b[i];
            break;
        }
    }
    if( c == -1){
        cout << *min_element(all(a))+k - *max_element(all(a)) + 1  << endl;
        return;
    }

    int cnt = 0;
    loop(i,0,n){

        if(b[i]!=-1) cnt++;
        

        if((b[i] != -1 && a[i] + b[i] != c) || c - a[i] > k || c - a[i] < 0){
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;
    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}