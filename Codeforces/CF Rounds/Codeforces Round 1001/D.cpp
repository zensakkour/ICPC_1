#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;

vector<int> g[MAXN+1];
long long L_val[MAXN+1], R_val[MAXN+1];
bool used_node[MAXN+1];

struct Info {
    long long cnt;  
    long long val;
};

long long global_max = 0;

Info dfs(int u, int p){
    used_node[u] = true;
    long long sumKids = 0, need = 0;
    for(int c : g[u]){
        if(c == p) continue;
        if(!used_node[c]){
            Info child = dfs(c, u);
            sumKids += child.cnt;
            need = max(need, child.val);
        }
    }

    long long chosen = max(L_val[u], need);
    long long extra = 0;
    if(chosen > R_val[u]){
        extra = chosen - R_val[u];
        chosen = R_val[u];
    }

    long long totalUp = sumKids + extra;

    // Debug Output
    // Uncomment the following lines when testing locally
    
    cout << "Node: " << u << "\n";
    cout << "  L_val: " << L_val[u] << ", R_val: " << R_val[u] << "\n";
    cout << "  sumKids: " << sumKids << ", need: " << need << "\n";
    cout << "  chosen: " << chosen << ", extra: " << extra << "\n";
    cout << "  totalUp: " << totalUp << "\n";
    cout << "  global_max before: " << global_max << "\n";
    

    global_max = max(global_max, chosen + sumKids);

    // More Debug Output
    /*
    cout << "  global_max after: " << global_max << "\n";
    */

    return {totalUp, chosen};
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1; i<=n; i++){
            cin >> L_val[i] >> R_val[i];
            g[i].clear();
            used_node[i] = false;
        }
        for(int i=0; i<n-1; i++){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        global_max = 0;

        int root = 1;
        for(int i=1;i<=n;i++){
            if((int)g[i].size() <=1){
                root = i;
                break;
            }
        }

        // Debug Output
        
        cout << "Test Case Start\n";
        cout << "Number of nodes: " << n << "\n";
        cout << "Edges:\n";
        for(int i=1;i<=n;i++){
            for(auto &v : g[i]){
                if(v > i) // To print each edge once
                    cout << "  " << i << " - " << v << "\n";
            }
        }
        cout << "Chosen root: " << root << "\n";
        

        Info ans = dfs(root, -1);

        // Debug Output
    
        cout << "Final global_max: " << global_max << "\n";
        cout << "Test Case End\n\n";
        

        cout << global_max << "\n";
    }

    return 0;
}
