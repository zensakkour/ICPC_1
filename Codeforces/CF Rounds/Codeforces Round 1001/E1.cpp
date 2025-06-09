#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> w(n+1);
        for(int i=1;i<=n;i++) cin >> w[i];
        vector<vector<int>> g(n+1, vector<int>());
        for(int i=1;i<n;i++){
            int x,y;
            cin >>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int max_w=0, total_max=0;
        for(int i=1;i<=n;i++) max_w = max(max_w, w[i]);
        for(int i=1;i<=n;i++) if(w[i]==max_w) total_max++;
        vector<int> parent(n+1,0);
        stack<int> s;
        s.push(1);
        parent[1]=-1;
        vector<int> order;
        while(!s.empty()){
            int u = s.top(); s.pop();
            order.push_back(u);
            for(auto &v: g[u]){
                if(v != parent[u]){
                    parent[v]=u;
                    s.push(v);
                }
            }
        }
        vector<int> cnt_max_sub(n+1,0);
        for(int i=order.size()-1;i>=0;i--){
            int u = order[i];
            if(w[u]==max_w) cnt_max_sub[u]++;
            for(auto &v: g[u]){
                if(v != parent[u]){
                    cnt_max_sub[u] += cnt_max_sub[v];
                }
            }
        }
        int ans=0;
        for(int u=1; u<=n; u++){
            if(w[u] <max_w && cnt_max_sub[u] < total_max){
                ans=u;
                break;
            }
        }
        cout << (ans ? ans :0) << "\n";
    }
}
