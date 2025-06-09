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
    string S;
    cin >> S;
    for (char c : S) {
        if (isupper(static_cast<unsigned char>(c))) {
            cout << c;
        }
    }
    cout << "\n";
    return;
}

int32_t main() {
    
    solve();
    

    return 0;
}