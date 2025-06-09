#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e10;

long long n;
vector<vector<long long>> capacity;
vector<vector<long long>> adj;
long long ptr[10000];

long long bfs(long long s, long long t, vector<long long>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<long long, long long>> q;
    q.push({s, INF});

    while (!q.empty()) {
        long long cur = q.front().first;
        long long flow = q.front().second;
        q.pop();

        for (long long next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                long long new_flow = min(flow, capacity[cur][next]);
                if (next == t){
                    // cout <<cur<<" "<<next<<" "<<new_flow<<endl;
                    return new_flow;}
                q.push({next, new_flow});
            }
            
            
        }
    }

    return 0;
}

long long maxflow(long long s, long long t) {
    long long flow = 0;
    vector<long long> parent(n);
    long long new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        

        long long cur = t;
        while (cur != s) {
            long long prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


int main() {
    long long G, C, T;
    cin >> G >> C >> T;

    vector<long long> cakePrices(C);
    vector<long long> ingredientPrices(G);
    vector<long long> toolPrices(T);


    n = 2 + C + T;

    capacity.assign(n, vector<long long>(n, 0));
    adj.assign(n, vector<long long>());

    long long source = 0;
    long long sink = n - 1;

    
    for (long long i = 0; i < C; i++) {
        cin >> cakePrices[i];
    }

    for (long long i = 0; i < G; i++) {
        cin >> ingredientPrices[i];
    }

    for (long long i = 0; i < T; i++) {
        cin >> toolPrices[i];
        adj[i + C +1].push_back(sink);
        adj[ sink].push_back(i + C);
        capacity[i + C +1][sink]= toolPrices[i];
        capacity[sink][i + C +1] = 0;
    }
    

    long long totalProfit=0;
    vector<vector<long long>> ingredients(C, vector<long long>(G));
    for (long long i = 0; i < C; i++) {
        long long cost=0;
        for (long long j = 0; j < G; j++) {
            cin >> ingredients[i][j];
            cost += ingredients[i][j]*ingredientPrices[j];

        }
        
        if (cost<=cakePrices[i]){
            adj[source].push_back(i + 1);
            adj[i + 1].push_back(source);
            capacity[source][i + 1] = cakePrices[i] - cost;
            // cout <<cakePrices[i] - cost<<endl;

            capacity[i + 1][source] = 0;
            totalProfit+=cakePrices[i] - cost;
        }
    }

    vector<vector<long long>> tools(C);
    for (long long i = 0; i < C;i++) {
        long long numTools;
        cin >> numTools;
        tools[i].resize(numTools,0);
        for (long long j = 0; j < numTools; j++) {
            cin >> tools[i][j];
            adj[i + 1].push_back(C + tools[i][j] );
            adj[C + tools[i][j]  ].push_back(i + 1);
            capacity[i + 1][C + tools[i][j]] = INF; 
            capacity[C + tools[i][j]][i + 1] = 0;
        }
    }
    
    
    
    
    long long maxFlow = maxflow(source, sink);
    cout <<totalProfit - maxFlow  << endl;
    return 0;
    


}