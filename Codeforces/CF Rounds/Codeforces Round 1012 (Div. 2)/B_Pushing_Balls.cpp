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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            v[i][j] = s[j] - '0';
        }
    }
    
    vector<vector<int>> c1(v);
    for(int i = 0; i < n; i++){
        int one = 1;
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0){
                one = 0;
            }
            c1[i][j] = one;
        }
    }

    vector<vector<int>> c2(v);
    for(int j = 0; j < m; j++){
        int one = 1;
        for(int i = 0; i < n; i++){
            if(v[i][j] == 0){
                one = 0;
            }
            c2[i][j] = one;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 1 && (c1[i][j] == 0 && c2[i][j] == 0) ){
                cout << "NO\n";
                goto next;
            }
        }
    }


    cout << "YES\n";
    next:
    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}