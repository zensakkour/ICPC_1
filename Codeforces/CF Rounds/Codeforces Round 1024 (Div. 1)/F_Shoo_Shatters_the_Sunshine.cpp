#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INV2 = (MOD + 1) >> 1;

struct C {
    int w;
    vector<int> s;
    long long s0, s1;
};
int add(int a,int b){int x=a+b; return x>=MOD?x-MOD:x;}
int mul(long long a,long long b){return int(a*b%MOD);}

C shift(const C& c,int d){
    if(!d) return c;
    C r=c;
    r.s.insert(r.s.begin(),d,0);
    r.s1 = (r.s1 + 1LL*r.s0*d)%MOD;
    return r;
}
C join(const C& A,const C& B){
    C R;
    R.w = mul(A.w,B.w);
    int n=max(A.s.size(),B.s.size());
    R.s.assign(n,0);
    for(int i=0;i<(int)A.s.size();++i) R.s[i]=add(R.s[i],mul(A.s[i],B.w));
    for(int j=0;j<(int)B.s.size();++j) R.s[j]=add(R.s[j],mul(B.s[j],A.w));
    for(int i=0;i<(int)A.s.size();++i) if(A.s[i])
        for(int j=0;j<(int)B.s.size();++j) if(B.s[j]){
            int d=max(i,j);
            R.s[d]=add(R.s[d],mul(mul(A.s[i],B.s[j]),INV2));
        }
    R.s0=R.s1=0;
    for(int i=0;i<n;++i){
        R.s0=(R.s0+R.s[i])%MOD;
        R.s1=(R.s1+1LL*R.s[i]*i)%MOD;
    }
    return R;
}

int n;
vector<vector<int>> g;
vector<C> down, up;
long long ans;

C dfs1(int v,int p){
    C cur; cur.w=1; cur.s={2}; cur.s0=2; cur.s1=0;
    for(int u:g[v]) if(u!=p) cur=join(cur,shift(dfs1(u,v),1));
    return down[v]=cur;
}

void vertex(const vector<C>& comps){
    if(comps.size()<2) return;
    int D=0; for(auto&c:comps) if(!c.s.empty()) D=max(D,(int)c.s.size()-1);
    static vector<vector<int>> dp;
    dp.assign(D+2,vector<int>(D+2,0));
    dp[0][0]=1;
    for(auto&c:comps){
        vector<vector<int>> ndp(D+2,vector<int>(D+2,0));
        for(int r=-1;r<=D;++r)
            for(int b=-1;b<=D;++b){
                int cur=dp[r+1][b+1]; if(!cur) continue;
                ndp[r+1][b+1] = add(ndp[r+1][b+1], mul(cur,c.w));
                for(int d=0; d<(int)c.s.size(); ++d) if(c.s[d]){
                    int half = mul(c.s[d], INV2);
                    int nr = (r==-1? d : max(r,d));
                    ndp[nr+1][b+1] = add(ndp[nr+1][b+1], mul(cur, half));
                    int nb = (b==-1? d : max(b,d));
                    ndp[r+1][nb+1] = add(ndp[r+1][nb+1], mul(cur, half));
                }
            }
        dp.swap(ndp);
    }
    for(int r=-1;r<=D;++r)
        for(int b=-1;b<=D;++b){
            int ways = dp[r+1][b+1]; if(!ways) continue;
            if(r!=-1 && b!=-1){
                ans = (ans + 1LL*(r+b)*ways)%MOD;          // centre white
                ans = (ans + 1LL*(r+b)*2%MOD*ways)%MOD;    // centre red / blue
            }
            else if(b!=-1){                               // only blue in comps
                ans = (ans + 1LL*b*ways)%MOD;             // centre red
            }
            else if(r!=-1){                               // only red in comps
                ans = (ans + 1LL*r*ways)%MOD;             // centre blue
            }
        }
}

void edge(const C& A,const C& B){
    long long SA0=A.s0, SA1=A.s1, SB0=B.s0, SB1=B.s1;
    long long add = 2LL*(SA1*SB0 + SA0*SB1 + SA0*SB0)%MOD;
    ans = (ans + add)%MOD;
}

void dfs2(int v,int p,const C& above){
    up[v]=above;
    vector<int> ch;
    for(int u:g[v]) if(u!=p) ch.push_back(u);
    int k=ch.size();
    vector<C> pref(k+1), suf(k+1);
    C base; base.w=1; base.s={2}; base.s0=2; base.s1=0;
    pref[0]=join(base,shift(above,1));
    for(int i=0;i<k;++i) pref[i+1]=join(pref[i],shift(down[ch[i]],1));
    suf[k]={1,{},0,0};
    for(int i=k-1;i>=0;--i) suf[i]=join(shift(down[ch[i]],1),suf[i+1]);

    vector<C> comps;
    for(int u:g[v]) comps.push_back(u==p?shift(above,1):shift(down[u],1));
    vertex(comps);

    for(int i=0;i<k;++i){
        C upc = join(pref[i], suf[i+1]);        // relative to v
        edge(down[ch[i]], upc);                 // (v,ch[i]) edge centre
        dfs2(ch[i], v, shift(upc,1));           // shift depths for the child
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        cin>>n; g.assign(n,{});
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v; --u; --v;
            g[u].push_back(v); g[v].push_back(u);
        }
        down.resize(n); up.resize(n); ans=0;
        dfs1(0,-1); dfs2(0,-1,{1,{},0,0});
        cout<<ans%MOD<<"\n";
    }
    return 0;
}
