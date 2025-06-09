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

/*
A + B 19 min
C  14 min
D  20 min

Total 53
*/

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int q;
    cin >> q;

    vector<array<int,26>> nxt(n + 2); // next pos > i tq c appears -1 if not

    int SENT = n + 1;
    for(int c = 0; c < k; c++){
        nxt[n][c] = SENT;
        nxt[n+1][c] = SENT;
    }
    for(int i = n - 1; i >= 0; i--){
        loop(c, 0, k){
            nxt[i][c] = nxt[i+1][c];
        }
        nxt[i][s[i] - 'a'] = i + 1; // pos (i + 1) c appears
    }

    //dp[i] min to append so not subseq
    vi dp(n+3, 0);
    for(int i = n; i >= 0; i--){
        int b = INF;
        bool m = false;
        for(int c = 0; c < k; c++){
            int nx = nxt[i][c];
            if(nx == SENT) m = true;
            else b = min(b, dp[nx]);
        }
        dp[i] = (m == true ? 1 : b + 1);
    }

    while(q--){
        string t;
        cin >> t;
        int pos = 0;
        bool isSub = true;
        for(char ch : t){
            pos = nxt[pos][ch - 'a'];
            if(pos == SENT){
                cout << 0 << endl;
                isSub = false;
                break;
            }
        }
        if(isSub){
            cout << dp[pos] << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}