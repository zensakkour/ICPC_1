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
    int n, q; cin >> n >> q;

    vector<int> p4(n+1);
    p4[0] = 1;
    for(int i = 1; i <= n; i++){
        p4[i] = p4[i-1] * 4ULL;
    }
    
    while(q--){
        int ans = 0;
        string op; cin >> op;
        if(op == "->"){
            int x, y; cin >> x >> y;
            int r = x -1, c  = y - 1;

            for(int i = n - 1; i >= 0; i--){
                int ri = (r >> i) & 1;
                int ci = (c >> i) & 1;
                int qidx;

                if(ri == 0 && ci == 0) qidx = 0;
                else if (ri == 1 && ci == 1) qidx = 1;
                else if (ri == 1 && ci == 0)   qidx = 2;
                else qidx = 3;

                ans += p4[i] * (int)qidx;
            }
        cout << ans + 1 << endl;
        }else{
            int d;
            cin >> d;

            d--;
            int r = 0, c = 0;

            for(int i = n - 1; i>=0;i--){
                int mb = p4[i];
                int qidx = (d/mb);
                d %= mb;

                int ri, ci;
                if (qidx == 0)       { ri = 0; ci = 0; }
                else if (qidx == 1)  { ri = 1; ci = 1; }
                else if (qidx == 2)  { ri = 1; ci = 0; }
                else  { ri = 0; ci = 1; }

                r |= (unsigned long long)ri << i;
                c |= (unsigned long long)ci << i;

            }

            cout << (r + 1) << " " << (c + 1) << endl;
        }
    }
    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}