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
const int MAXN = 500000 + 5;   
//LCT
struct Node{ int p=0,l=0,r=0,w=0,s=0; } T[MAXN];

inline bool isRoot(int x){ int p=T[x].p; return T[p].l!=x && T[p].r!=x; }
inline int  dir(int x){ return T[T[x].p].r==x; }

inline void pull(int x){
    T[x].s = T[x].w;
    if(T[x].l) T[x].s += T[T[x].l].s;
    if(T[x].r) T[x].s += T[T[x].r].s;
}

void rot(int x){
    int p=T[x].p, d=dir(x), g=T[p].p;
    if(!isRoot(p)) (dir(p)?T[g].r:T[g].l) = x;
    T[x].p=g;

    if(d==0){
        T[p].l = T[x].r; if(T[x].r) T[T[x].r].p = p;
        T[x].r = p;
    }else{
        T[p].r = T[x].l; if(T[x].l) T[T[x].l].p = p;
        T[x].l = p;
    }
    T[p].p = x;
    pull(p); pull(x);
}

void splay(int x){
    while(!isRoot(x)){
        int p=T[x].p;
        if(!isRoot(p))
            (dir(x)==dir(p)?rot(p):rot(x));
        rot(x);
    }
}

int acc(int x){
    int last=0;
    for(int u=x; u; u=T[u].p){
        splay(u);
        T[u].r = last;
        pull(u);
        last=u;
    }
    return last;
}
inline void linkNodes(int x,int y){ acc(x); splay(x); T[x].p=y; }
inline void cutEdge (int x,int y){ acc(y); splay(x); T[x].p=0; }

void solve(){
    int n,d; cin>>n>>d;
    vector<pii> a(n); // {heigt,pos}
    loop(i,0,n){ cin>>a[i].F; a[i].S=i+1; }
    sort(all(a),[&](pii A,pii B){
        return A.F<B.F || (A.F==B.F && A.S<B.S);
    });

    loop(i,1,n+2) T[i] = Node();
    loop(i,1,n+1)  T[i].p = i+1;           

    int idx= n-1;           
    long long ans =0;
    while(idx >= 0){
        long long curH = a[idx].F;

        while(idx>=0 && a[idx].F == curH){
            int pos= a[idx].S;
            cutEdge(pos, pos+1);                    
            linkNodes(pos, min(n+1, pos+d));       
            T[pos].w = 1; pull(pos);              
            --idx;
        }

        acc(1); splay(1);
        long long active = T[1].s;

        long long nextH = (idx>=0 ? a[idx].F : 0); 
        ans += (curH - nextH) * active;           
    }
    cout<<ans<<endl;
}


int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
