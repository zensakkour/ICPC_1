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

void ct(char c){
    if(c == 'A')cout << "Alice\n";
    else cout << "Bob\n";
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnta = 0, cntb = 0;
    for(auto c : s){
        if(c == 'A')cnta++;
        else cntb++;
    }
    if(s[0] == s[n-1]){ 
        ct(s[0]); // has 1 and n
        return;
    }
    if(s[n-1] == 'A'){
        if(cnta >1 && s[n-2]=='A')ct(s[n-1]);
        else ct(s[0]);
    }else{
        if(cntb >1)ct(s[n-1]);
        else ct(s[0]);
    }
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}