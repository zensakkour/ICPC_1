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

void solve(){
    int n, h; cin >> n >> h;
    int d1 = 0, d2 = 0;
    loop(i,0,n){
        int s, d; cin >> s >> d;
        if(s==1) d1 = max(d1, d);
        else d2 = max(d2, d);
    }
    int ans;
    if(d1== 0){
        ans= 2 *((h + d2 - 1) / d2);
    }else if(d2==0){
        ans = (h + d1 - 1) / d1;
    }else{
        if(d1 * 2 >= d2){
            ans = (h + d1 - 1) / d1;
        }else{
            int y1 = (h + d2 -1) / d2;
            int t1 = 2 * y1;
            int y0 = h / d2;
            int rem = h - y0 * d2;
            int t0 = 2 * y0 + (rem ?(rem + d1 - 1) / d1 :0);
            ans = min(t0, t1);
        }
    }
    cout<<ans<<endl;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}