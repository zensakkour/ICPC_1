#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;
static const int MAXM = 200000;
static const int INF  = 1000000007;

struct Node {
    int mn, tag, l, r;
} seg[40 * MAXN];
int nxtNode;

int cloneNode(int v) {
    int u = nxtNode++;
    seg[u] = seg[v];
    return u;
}
int build0(int L,int R) {
    int v = nxtNode++;
    seg[v].mn  = 0;
    seg[v].tag = 0;
    seg[v].l = seg[v].r = 0;
    if (L < R) {
        int M = (L+R)>>1;
        seg[v].l = build0(L, M);
        seg[v].r = build0(M+1, R);
    }
    return v;
}
int upd(int v,int L,int R,int ql,int qr,int val) {
    if (qr<L || R<ql) return v;
    int u = cloneNode(v);
    if (ql<=L && R<=qr) {
        seg[u].mn  = val;
        seg[u].tag = val;
        seg[u].l = seg[u].r = 0;
        return u;
    }
    if (seg[u].tag != -1) {
        int tg = seg[u].tag;
        seg[u].l = cloneNode(seg[u].l);
        seg[ seg[u].l ].mn  = tg;
        seg[ seg[u].l ].tag = tg;
        seg[ seg[u].l ].l = seg[ seg[u].l ].r = 0;
        seg[u].r = cloneNode(seg[u].r);
        seg[ seg[u].r ].mn  = tg;
        seg[ seg[u].r ].tag = tg;
        seg[ seg[u].r ].l = seg[ seg[u].r ].r = 0;
        seg[u].tag = -1;
    }
    int M=(L+R)>>1;
    seg[u].l = upd(seg[u].l, L,   M, ql,qr,val);
    seg[u].r = upd(seg[u].r, M+1, R, ql,qr,val);
    int lm = seg[u].l ? seg[ seg[u].l ].mn : INT_MAX;
    int rm = seg[u].r ? seg[ seg[u].r ].mn : INT_MAX;
    seg[u].mn = min(lm, rm);
    return u;
}
int qry(int v,int L,int R,int ql,int qr) {
    if (!v || qr<L || R<ql) return INT_MAX;
    if (ql<=L && R<=qr) return seg[v].mn;
    if (seg[v].tag != -1) return seg[v].tag;
    int M=(L+R)>>1;
    return min(
      qry(seg[v].l, L,   M, ql,qr),
      qry(seg[v].r, M+1, R, ql,qr)
    );
}

struct RMQ {
    int n; vector<int> st;
    RMQ(int _n=0): n(_n), st(4*_n, INT_MAX) {}
    void build(int p,int L,int R,const int *a){
        if (L==R) {
            st[p]=a[L];
            return;
        }
        int M=(L+R)>>1;
        build(p<<1,   L,M,a);
        build(p<<1|1,M+1,R,a);
        st[p]=min(st[p<<1], st[p<<1|1]);
    }
    int query(int p,int L,int R,int ql,int qr){
        if (qr<L||R<ql) return INT_MAX;
        if (ql<=L&&R<=qr) return st[p];
        int M=(L+R)>>1;
        return min(
          query(p<<1,  L,  M,ql,qr),
          query(p<<1|1,M+1,R,ql,qr)
        );
    }
};


int tp[MAXM+1], Lc[MAXM+1], Rc[MAXM+1];
int highV[MAXM+1], lowV[MAXM+1];
int rootF[MAXM+1], rootB[MAXM+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int n,m; cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>tp[i]>>Lc[i]>>Rc[i];
        }
        nxtNode = 1;
        rootF[0] = build0(1,n);
        for(int i=1;i<=m;i++){
            if(tp[i]==0)
                rootF[i] = upd(rootF[i-1],1,n,Lc[i],Rc[i], i);
            else
                rootF[i] = rootF[i-1];
        }
        for(int i=1;i<=m;i++){
            if(tp[i]==0){
                highV[i] = m+1;
            } else {
                if(qry(rootF[m],1,n,Lc[i],Rc[i]) < i){
                    highV[i] = m+1;
                } else {
                    int lo=i, hi=m, ans=m;
                    while(lo<=hi){
                        int mid=(lo+hi)>>1;
                        if(qry(rootF[mid],1,n,Lc[i],Rc[i]) >= i){
                            ans=mid; hi=mid-1;
                        } else lo=mid+1;
                    }
                    highV[i] = ans;
                }
            }
        }

       
        nxtNode = 1;
        rootB[0] = build0(1,n);
        for(int i=1;i<=m;i++){
            int j = m - i + 1;
            if(tp[j]==0)
                rootB[i] = upd(rootB[i-1],1,n,Lc[j],Rc[j], i);
            else
                rootB[i] = rootB[i-1];
        }
        for(int i=1;i<=m;i++){
            if(tp[i]==0){
                lowV[i] = 0;
            } else {
                int revI = m - i + 1;
                if(qry(rootB[m],1,n,Lc[i],Rc[i]) < revI){
                    lowV[i] = 0;
                } else {
                    int lo=revI, hi=m, ans=m;
                    while(lo<=hi){
                        int mid=(lo+hi)>>1;
                        if(qry(rootB[mid],1,n,Lc[i],Rc[i]) >= revI){
                            ans=mid; hi=mid-1;
                        } else lo=mid+1;
                    }
                    lowV[i] = m - ans + 1;
                }
            }
        }

  
        static int tmp[MAXM+1];
        for(int i=1;i<=m;i++) tmp[i] = -lowV[i];
        RMQ rmqLow(m);
        rmqLow.build(1,1,m,tmp);
        for(int i=1;i<=m;i++) tmp[i] = highV[i];
        RMQ rmqHigh(m);
        rmqHigh.build(1,1,m,tmp);

        int Q; cin>>Q;
        while(Q--){
            int l,r; cin>>l>>r;
            int bestLow  = -rmqLow.query(1,1,m,l,r);
            int bestHigh =  rmqHigh.query(1,1,m,l,r);
            cout << ((bestLow <= l && bestHigh >= r) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
