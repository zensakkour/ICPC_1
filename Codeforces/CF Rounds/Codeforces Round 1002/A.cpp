#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
    vector<long long>a(n),b(n);
    
    for(auto &x:a )cin >>x;
    for(auto &x:b)cin>>x;
    
    unordered_set<long long >sa(a.begin(),a.end()),sb(b.begin(),b.end());
    int da=sa.size(), db=sb.size();
    if(da>=3||db>=3) cout<<"YES\n";
    else if(da==2&& db==2)cout<<"YES\n";
    else cout<<"NO\n";}return 0;
    
    }
