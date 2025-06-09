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

const int NMAX = 200000 + 5;

int n;
vector<int> g[NMAX];
int sub[NMAX], up[NMAX];

int dfs_size(int u,int p){
    up[u]=p; sub[u]=1;
    for(int v:g[u]) if(v!=p) sub[u]+=dfs_size(v,u);
    return sub[u];
}
int centroid(int r){
    dfs_size(r,-1);
    int c=r,move=1;
    while(move){
        move=0;
        for(int v:g[c])
            if(v!=up[c] && sub[v]*2>n){ c=v; move=1; break; }
        if(!move && (n-sub[c])*2>n){ c=up[c]; move=1; }
    }
    return c;
}
int leaf,leafPar;
void bfs_leaf(int c){
    queue<int> q; vector<int> par(n,-1);
    q.push(c); par[c]=-2;
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(u!=c && sz(g[u])==1){ leaf=u; leafPar=par[u]; return; }
        for(int v:g[u]) if(v!=par[u]){ par[v]=u; q.push(v); }
    }
}
vector<int> bucket[NMAX];
void collect(int u,int p,int id){
    bucket[id].pb(u);
    for(int v:g[u]) if(v!=p) collect(v,u,id);
}

void solve(){
    cin>>n;
    loop(i,0,n){ g[i].clear(); }
    loop(i,0,n-1){
        int u,v;cin>>u>>v;--u;--v;
        g[u].pb(v); g[v].pb(u);
    }

    int cen=centroid(0);
    bfs_leaf(cen);

    int rem=leaf, keep=leafPar;
    if(rem<keep) swap(rem,keep);         
    int half=(n-1)/2;
    vector<int> col(n,0);

    int bid=0;
    for(int v:g[cen]){ bucket[bid].clear(); collect(v,cen,bid); ++bid; }
    int small= 0;
    loop(i,1,bid) if(sz(bucket[i])<sz(bucket[small])) small=i;
    bucket[small].pb(cen);                

    priority_queue<pair<int,int>> pq;
    loop(i,0,bid) if(!bucket[i].empty()) pq.push({sz(bucket[i]),i});

    int cur=1;
    auto nextCol=[&](){ int x =  cur; ++cur; if(cur>half) cur =1; return x; };

    while(!pq.empty()){
        if(sz(pq)>=2){
            auto [s1,i1]=pq.top(); pq.pop();
            auto [s2,i2]=pq.top(); pq.pop();
            int x=bucket[i1].back(); bucket[i1].pop_back();
            int y=bucket[i2].back(); bucket[i2].pop_back();
            int c=nextCol();
            if(x!=rem) col[x]=c;
            if(y!=rem) col[y]= c;

            if(!bucket[i1].empty())pq.push({sz(bucket[i1]),i1});
            if(!bucket[i2].empty()) pq.push({sz(bucket[i2]),i2});
        }else{
            auto [_,id]=pq.top(); pq.pop();
            while(sz(bucket[id])>=2){
                int x=bucket[id].back();bucket[id].pop_back();
                int y=bucket[id].back(); bucket[id].pop_back();
                int c=nextCol();
                if(x!=rem) col[x]=c;
                if(y!=rem) col[y]=c;
            }
        }
    }
    col[rem]=0;

    cout<<keep+1<<" "<<rem+1<<endl;
    loop(i,0,n){ if(i) cout<<' '; cout<<col[i]; }
    cout<<endl;
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}