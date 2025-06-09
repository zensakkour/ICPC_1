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
    string s; cin >> s;
    int cnt = 0,mx = 0;
    vi v(sz(s));
    int last=0;
    v[0]=s[0]=='0';
    for(int i = 1; i < sz(s); i++){
        v[i]=v[i-1]+(s[i]=='0');
        if(s[i]!='0')last=i;
    }
    cout <<sz(s)-v[last]-1<< endl;
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}