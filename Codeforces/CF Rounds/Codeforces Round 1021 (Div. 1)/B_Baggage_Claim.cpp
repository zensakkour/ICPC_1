#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'

static const int MOD = 1'000'000'007LL;

int addm(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int mulm(int a, int b) {
    return (a * b) % MOD;
}

int solve_tree(const vector<vi>& g, const vi& vars) {
    unordered_map<int, int> id;
    vi cells;
    for (int v : vars) {
        for (int c : g[v]) {
            if (!id.count(c)) {
                id[c] = sz(cells);
                cells.pb(c);
            }
        }
    }

    int nv = sz(vars), nc = sz(cells);
    vector<vi> v2c(nv),c2v(nc);
    for (int i = 0; i < nv; ++i) {
        for (int c : g[vars[i]]) {
            int j = id[c];
            v2c[i].pb(j);
            c2v[j].pb(i);
        }
    }

    vi pv(nc, -1), pc(nv, -1);
    vector<pair<char, int>> post;
    vector<tuple<char,int, int>> st = {{'v', 0, -1}};
    while (!st.empty()) {
        auto [t, x, p] = st.back();
        st.pop_back();
        if (t == 'V') {
            post.pb({'v', x});
            continue;
        }
        if (t == 'C') {
            post.pb({'c', x});
            continue;
        }
        if (t == 'v') {
            st.pb({'V',x, p});
            for (int c : v2c[x]) {
                if (c != p) {
                    pv[c] = x;
                    st.pb({'c', c, x});
                }
            }
        } else {
            st.pb({'C', x, p});
            for (int v : c2v[x]) {
                if (v != p) {
                    pc[v] = x;
                    st.pb({'v', v, x});
                }
            }
        }
    }

    vi dv0(nv),dv1(nv), dc0(nc), dc1(nc);
    for (auto [t, x] : post) {
        if (t == 'c') {
            int prod = 1;
            vi ch;
            for (int v : c2v[x]) {
                if (v!= pv[x]) {
                    prod = mulm(prod, dv1[v]);
                    ch.pb(v);
                }
            }
            int g0 = prod, g1 = prod;
            for (int v : ch) {
                int term = dv0[v];
                for (int u : ch) {
                    if (u != v) {
                        term = mulm(term, dv1[u]);
                    }
                }
                g1 =addm(g1, term);
            }
            dc0[x] = g0;
            dc1[x] = g1;
        } else {
            int prod = 1;
            vi ch;
            for (int c: v2c[x]) {
                if (c != pc[x]) {
                    prod = mulm(prod, dc1[c]);
                    ch.pb(c);
                }
            }
            dv0[x] = prod;
            int f1 = 0;
            for (int c: ch) {
                int term = dc0[c];
                for (int d : ch) {
                    if (d != c) {
                        term = mulm(term, dc1[d]);
                    }
                }
                f1 = addm(f1, term);
            }
            dv1[x]= f1;
        }
    }

    int res = 0;
    for (int c : v2c[0]) {
        int term = dc0[c];
        for (int d : v2c[0]) {
            if (d != c) {
                term = mulm(term, dc1[d]);
            }
        }
        res = addm(res, term);
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii>odd(k + 1);
    for (auto& p : odd) {
        cin >> p.F >> p.S;
    }

    vi idOk(n *m, 0);
    for (auto& p : odd) {
        idOk[(p.F - 1) * m + p.S - 1] = 1;
    }

    vector<vi> g(k);
    for (int i = 0; i < k; ++i) {
        auto [x1, y1] = odd[i];
        auto [x2, y2] = odd[i + 1];
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        if (dx + dy != 2) {
            cout << 0 << endl;
            return;
        }

        vi cand;
        if (dx== 2) {
            int cx = min(x1, x2) + 1, cy = y1;
            int id = (cx - 1) * m + cy - 1;
            if (!idOk[id]) cand.pb(id);
        } else if (dy == 2) {
            int cy= min(y1, y2) + 1, cx = x1;
            int id = (cx - 1) * m + cy - 1;
            if (!idOk[id]) cand.pb(id);
        } else {
            int id1 = (x1 - 1) * m + y2 - 1;
            int id2 = (x2 - 1)* m + y1 - 1;
            if (!idOk[id1]) cand.pb(id1);
            if (id2 != id1 && !idOk[id2]) cand.pb(id2);
        }
        if (cand.empty()) {
            cout << 0 << endl;
            return;
        }
        g[i]= cand;
    }

    unordered_map<int, vi> cellAdj;
    for (int v = 0; v < k; ++v) {
        for (int c : g[v]) {
            cellAdj[c].pb(v);
        }
    }

    vi visV(k, 0);
    unordered_set<int> visC;
    int ans = 1;
    for (int v0 = 0;v0 < k; ++v0) {
        if (visV[v0]) continue;
        vi st = {v0},vars, cells;
        long long edges = 0;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            if (visV[v]) continue;
            visV[v] = 1;
            vars.pb(v);
            edges +=sz(g[v]);
            for (int c : g[v]) {
                if (!visC.count(c)) {
                    visC.insert(c);
                    cells.pb(c);
                }
            }
            for (int c : g[v]) for (int u : cellAdj[c]) if (!visV[u]) st.pb(u);
        }
        long long cyc= edges - sz(vars) - sz(cells) + 1;
        long long ways;
        if (cyc == 0) ways = solve_tree(g, vars);
        else ways = (sz(vars) != sz(cells)) ? 0 : 2;
        ans = mulm(ans, ways);
        for (int c : cells) visC.erase(c);
    }
    cout <<ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();

    return 0;
}