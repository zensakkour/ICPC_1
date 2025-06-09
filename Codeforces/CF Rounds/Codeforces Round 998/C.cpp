#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k; vector<int> a(n);
        for(auto &x:a) cin>>x;
        int m=*max_element(a.begin(),a.end());
        vector<int> c(m+1,0); for(auto x:a) c[x]++;
        long long ans=0;
        for(int x=1; x*2<k && x<=m;x++){
            int y=k-x;
            if(y<=m) ans += min(c[x],c[y]);
        }
        if(k%2==0){
            int x=k/2;
            if(x<=m) ans += c[x]/2;
        }
        cout<<ans<<"\n";
        }
    return 0;
    }
