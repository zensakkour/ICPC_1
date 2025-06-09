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

bool check(const vi &a, const vi &b, int n, int m){
    int j = 0;
    loop(i, 0, n){
        if(j == m) return true;
        if(a[i]>= b[j])j++;
    }
    if(j == m) return true;
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    loop(i, 0, n)cin >> a[i];
    loop(i, 0, m) cin >> b[i];
    if(check(a, b, n, m)){
        cout << 0 << endl;
        return;
    }
    vi perf(n + 2,0), suff(n + 2,0);
    int j = 0;
    loop(i, 0, n){
        if(j < m && a[i] >= b[j]){
            j++;
        }
        perf[i] = j;
    }
    j = m - 1;
    for(int i = n - 1; i >= 0; i--){
        if(j >= 0 && a[i] >= b[j]){
            j--;
        }
        suff[i] = m - 1 - j;
    }
    auto cank = [&](int k){
        int plus;
        if(k >= b[0] && suff[0] >= m - 1)return true;
        if(k >= b[m - 1] && perf[n - 1] >= m - 1)return true;
        for(int i = 0; i < n - 1; i++){
            plus = (perf[i] < m && k >= b[perf[i]] ? 1 : 0);
            if(perf[i] + plus + suff[i + 1] >= m)return true;
        }
        return false;
    };
    vector<int> vals = b;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int lw = 0, hi = sz(vals) - 1, mid, ans = - 1;
    while(lw <= hi){
        mid = lw + (hi - lw)/2;
        if(cank(vals[mid])){
            ans = vals[mid];
            hi = mid - 1; 
        }else lw = mid + 1;
    }
    if(ans != -1)cout << ans << endl;    
    else cout << -1 << endl;

    
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}