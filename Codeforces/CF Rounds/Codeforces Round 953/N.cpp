#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> L, R;
vector<vector<int>> adj;
 
// DFS: for candidate X, compute for each node v an interval [lv, rv] of “extra” that can be pushed up.
// (This version uses delta = L[u] - L[v].)
pair<ll,ll> dfs(int v, int p, ll X) {
    ll lo = 0, hi = R[v] - L[v]; // available slack at v
    for (int u : adj[v]) {
        if(u==p) continue;
        auto pr = dfs(u, v, X);
        ll d = L[u] - L[v];  // the delta adjustment (try changing this to R[u]-R[v] if needed)
        lo = max(lo, pr.first - d);
        hi = min(hi, pr.second - d);
    }
    return {lo, hi};
}
 
// Check if candidate X is feasible (choose an appropriate root)
bool feasible(ll X) {
    if(X < *max_element(L.begin(), L.end())) return false;
    // Here we choose root = argmax(L). (This can be important.)
    int rt = max_element(L.begin(), L.end()) - L.begin();
    auto pr = dfs(rt, -1, X);
    return (pr.first <= 0 && 0 <= pr.second);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n;
        L.resize(n); R.resize(n);
        for (int i = 0; i < n; i++){
            cin >> L[i] >> R[i];
        }
        adj.assign(n, {});
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll loX = *max_element(L.begin(), L.end());
        ll hiX = loX;
        for (int i = 0; i < n; i++){
            hiX += (R[i]-L[i]);
        }
        ll ans = hiX;
        while(loX <= hiX){
            ll mid = loX + (hiX-loX)/2;
            if(feasible(mid)){
                ans = mid;
                hiX = mid - 1;
            } else {
                loX = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
