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
    int n, k; cin >> n >> k;
    vi a(n);
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    vi suffix_scro;
    int scr = 0;
    for(int i = n-1; i > 0; i--){
        if(a[i] == 1){
            scr++;
        }else{
            scr--;
        }
        suffix_scro.pb(scr);
    }
    sort(all(suffix_scro), greater<int>());
    int ans = 0, i = 1;
    while(ans < k){
        if(i > sz(suffix_scro)) break;
        ans += suffix_scro[i - 1];
        i++;
    }
    if(ans < k){
        cout << -1 << endl;
    }else{cout << i  << endl;}
    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}