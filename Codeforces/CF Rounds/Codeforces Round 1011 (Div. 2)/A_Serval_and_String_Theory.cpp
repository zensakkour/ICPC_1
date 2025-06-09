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
    int n, k; 
    string s;
    cin >> n >> k >> s;
    if(n==1){
        cout << "NO\n";
        return;
    }

    string rev = s;
    reverse(rev.begin(), rev.end());
    if(s < rev){
        cout << "YES\n";
        return;
    }
    if(k == 0){
        cout << "NO\n";
        return;
    }

    bool eq = true;
    for(int i = 1; i < n; i++){
        if(s[i] != s[0]){
            eq = false;
            break;
        }
    }
    cout << (eq ? "NO\n" : "YES\n");
    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}