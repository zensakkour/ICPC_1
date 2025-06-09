#include <bits/stdc++.h>
using namespace std;


pair<int,int> intersect(vector<pair<int,int>> s){
    int r=1e7,l=-1*1e7;
    for(auto p : s){
        r=min(r,p.second);
        l=max(l,p.first);
    }
    return make_pair(l,r);
}


int main(){
    int t,n,k;
    cin >>t;
    vector<pair<int,int>> s;
    int l,r;
    while(t--){
        s.clear();
        cin >>n>>k;
        for(int i=0;i<n;i++){
            cin >>l>>r;
            if(l<=k && k<=r)s.push_back(make_pair(l,r));
        }
        if(s.size()==0){cout <<"NO"<<endl;continue;}
        while(s.size()!=0){
            auto p=intersect(s);
            if(p.first==p.second && p.second==k){cout <<"YES"<<endl;break;}
            s.pop_back();
        }
        if(s.size()==0)cout <<"NO"<<endl;
        
        
    }
    return 0;
}