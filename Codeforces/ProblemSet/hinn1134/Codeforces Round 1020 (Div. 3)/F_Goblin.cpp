#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb  push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define loop(i,a,b) for (int i=(a), _b=(b); i<_b; ++i)


struct Tarjan {
    const vector<vector<int>>& g;
    const vector<long long>&   w; 
    int n;
    vector<int> disc, low, st;
    vector<char> inSt;
    int timer = 0;
    long long best = 0;

    Tarjan(const vector<vector<int>>& _g,const vector<long long>&   _w): g(_g), w(_w), n(sz(_g)),disc(n, -1), low(n, 0),inSt(n, 0) {                      
        for (int v = 0; v < n; ++v)
            if (disc[v] == -1) dfs(v);
    }

    void dfs(int u) {
        disc[u] = low[u] = ++timer;
        st.pb(u);  inSt[u] = 1;

        for (int v : g[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inSt[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {          
            long long acc = 0;
            while (true) {
                int v = st.back(); st.pop_back();
                inSt[v] = 0;
                acc += w[v];
                if (v == u) break;
            }
            best = max(best, acc);
        }
    }
};

struct Run {
    int L, R;          
    long long up, dn;  
    int idU, idD;     
};

void solve() {
    int n;cin >> n;
    string s; cin >> s;

    vector<long long> pref(n+1,0);
    loop(i,0,n) pref[i+1]= pref[i] + i;
    auto sumIdx = [&](int l,int r){ return pref[r+1]-pref[l]; };

    vector<Run> runs;
    vector<int>  runOfCol(n,-1);

    for (int j=0; j<n; ) {
        if (s[j]=='1' ){ ++j; continue; }
        int L=j; while (j<n && s[j]=='0') ++j;
        int R = j-1;
        long long U = sumIdx(L,R);
        long long D= (R-L+1)*(n-1LL) - U;
        runs.push_back({L,R,U,D,-1,-1});
        int idx = sz(runs)-1;
        loop(c,L,R+1) runOfCol[c]=idx;
    }

    int V_est = 2*sz(runs) + count(all(s),'1');
    vector<vector<int>> adj(V_est);
    vector<long long>   w(V_est,0);
    int nxt = 0;

    for (auto& ru : runs) {
        ru.idU = nxt;w[nxt++] = ru.up;
        ru.idD = nxt; w[nxt++] = ru.dn;

    }

    for (int i=0;i<n;++i) if (s[i]=='1') {
        int diag = nxt; w[nxt++] = 1;
        if (i>0 && s[i-1]=='0') {
            int r = runOfCol[i-1];
            adj[diag].pb(runs[r].idD);
            adj[runs[r].idD].pb(diag);
        }

        if (i+1<n &&s[i+1]=='0') {
            int r = runOfCol[i+1];
            adj[diag].pb(runs[r].idU);
            adj[runs[ r].idU].pb(diag);
        }
    }

    adj.resize(nxt); w.resize(nxt);   

    Tarjan scc(adj, w);
    cout << scc.best << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}
