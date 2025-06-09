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
    int n, q; cin >> n >> q;
    vi p(n), pos(n + 1);
    loop(i, 0, n){
        cin >> p[i];
        pos[p[i]]=i;
    }
    int l, r, k;
    loop(i, 0, q){
        cin >> l >> r >> k;
        l--;r--;
        if(pos[k]< l || pos[k] > r){
            cout << -1 << " ";
            continue;
        }
        int ws = 0, wl = 0, sp = 0, bp = 0;
        int hi = r, lw = l, mid;
        while(true){
            mid = lw + (hi - lw )/2;

            if (p[mid] < k) ++sp;
            else if (p[mid] > k) ++bp;

            if(p[mid] == k){
                break;
            }
            if(mid < pos[k]){
                if(p[mid] > k){
                    ws++;
                }
                lw = mid + 1;
            }else{
                if(p[mid] < k)wl++;
                hi = mid - 1;
            }
            
        }
        int needs = max(ws - wl,0LL), needl = max(wl-ws,0LL);
        if(needs > (k-1)-sp || needl > (n-k)-bp){
            cout << -1 << " ";
        }else cout << 2 * max(ws, wl) << " ";

        

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