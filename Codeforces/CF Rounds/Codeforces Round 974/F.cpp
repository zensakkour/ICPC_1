#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX/4;
vector<long long> dp;
vector<long long> a;
vector<vector<int>> g;
long long c;

long long dfs(int v, int p){
    long long res = a[v];
    for(int w: g[v]){
        if(w == p) continue;
        long long sub = dfs(w, v);

        if(sub - 2*c > 0) res += (sub - 2*c);
        
    }
    dp[v] = res;
    return res;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n >> c;
        a.resize(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        g.assign(n, {});
        for(int i=0;i<n-1;i++){
            int u,v; cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dp.assign(n, -INF);
        dfs(0, -1);
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
