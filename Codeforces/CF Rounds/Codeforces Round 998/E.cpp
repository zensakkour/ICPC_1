#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n):n(n),p(n),r(n,0 ){ for(int i=0;i<n;i++) p[i]=i; }
    int findp(int x){return p[x ]==x?x:(p[x]=findp(p[x]));}
    void unite(int x,int y ){
        x=findp(x); 
        y=findp(y);
        if(x==y) return;

        if(r[x]<r[y])p[x]=y; 
        else if(r[x]>r[y])p[y]=x;

        else p[y]=x, r[x]++;
    }
};

int main(){

    int t; cin>>t;
    while(t--){
        int n,m1,m2;cin>>n>>m1>>m2;
        vector<vector<int>> adjF(n);
        vector<pair<int,int>> edgesF(m1);

        for(int i=0;i<m1;i++){
            int u,v;cin>>u>>v; 
            --u;--v;
            edgesF[i]={u,v};
        }

        DSU dsuG(n);
        for(int i=0;i<m2;i++){
            int u,v;cin>>u>>v; 
            --u;--v;
            dsuG.unite(u,v);
        }

        long long removals=0;

        for(auto &e:  edgesF){
            int pu=dsuG.findp(e.first ),pv=dsuG.findp(e.second);
            if(pu !=pv ){
                removals++;
            } else {
                adjF[e.first].push_back(e.second);

                adjF[e.second].push_back(e.first);
            }
        }

        DSU dsuFNew(n);
         
        for(int i=0;i<n; i++){
            for(int nei: adjF[i]){
                if(i<nei ) dsuFNew.unite(i,nei);
            }
        }

        unordered_map<int,vector<int>> gCompToVertices;
        gCompToVertices.reserve(n );

        gCompToVertices.max_load_factor( 0.7f);
        for(int i=0;i<n;i++){
            int cG=dsuG.findp(i);
            gCompToVertices[cG ].push_back(i);
        }

        long long additions=0;
        for(auto &it : gCompToVertices){
            auto &nodes = it.second;
            unordered_set<int> fComps;
            fComps.reserve(nodes.size());
            fComps.max_load_factor(0.7f);
            for(auto &x: nodes){
                fComps.insert(dsuFNew.findp(x));
            }
            additions += (long long)fComps.size()-1;
        }

        cout<<removals + additions<<"\n";
    }
    return 0;
}
