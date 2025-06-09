#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX / 4;

struct Edge {
    int to;
    long long w;
};

struct State {
    long long dist;
    int v;
    bool h;
    bool operator>(const State &o) const {
        return dist > o.dist;
    }
};

void dijkstra(int n, const vector<vector<Edge>>& g, const unordered_set<int>& horse, int start,
              vector<long long>& dNo, vector<long long>& dH) {
    for(int i = 0; i < n; i++){
        dNo[i] = INF;
        dH[i] = INF;
    }
    dNo[start] = 0;
    if (horse.count(start)) dH[start] = 0;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, start, false});
    if (dH[start] == 0) pq.push({0, start, true});
    while(!pq.empty()){
        auto [cd, u, hh] = pq.top();
        pq.pop();
        if (!hh && cd > dNo[u]) continue;
        if ( hh && cd > dH[u]) continue;
        if (!hh && horse.count(u) && dH[u] > cd) {
            dH[u] = cd;
            pq.push({cd, u, true});
        }
        for (auto &e : g[u]) {
            long long cost = hh ? e.w / 2 : e.w;
            long long nd = cd + cost;
            if (!hh && nd < dNo[e.to]) {
                dNo[e.to] = nd;
                pq.push({nd, e.to, false});
            } else if (hh && nd < dH[e.to]) {
                dH[e.to] = nd;
                pq.push({nd, e.to, true});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m, h;
        cin >> n >> m >> h;
        unordered_set<int> horse;
        horse.reserve(h);
        for(int i = 0; i < h; i++){
            int x; cin >> x; x--;
            horse.insert(x);
        }
        vector<vector<Edge>> g(n);
        for(int i = 0; i < m; i++){
            int u, v;
            long long w;
            cin >> u >> v >> w;
            u--; v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vector<long long> dnM(n), dhM(n), dnR(n), dhR(n);
        dijkstra(n, g, horse, 0, dnM, dhM);
        dijkstra(n, g, horse, n - 1, dnR, dhR);
        long long ans = INF;
        for(int i = 0; i < n; i++){
            long long a = min(dnM[i], dhM[i]);
            long long b = min(dnR[i], dhR[i]);
            if (a == INF || b == INF) continue;
            ans = min(ans, max(a, b));
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
}
