#include<bits/stdc++.h>
using namespace std;

int maint(){
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        vector<int> h,x;
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            h.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            cin>>tmp;
            x.push_back(tmp);
        }

        interval:
        vector<pair<int,int>> interval;
        int k;
        for(int i=0;i<n;i++){
            interval.push_back(make_pair(x[i]-m+(h[i]/k +(h[i]%k!=0)),0));
            interval.push_back(make_pair(x[i]+m+(h[i]/k +(h[i]%k!=0)),1));
        }
        sort(interval.begin(),interval.end());

        int cnt=0;
        for(auto c : interval){
            if (c.second==0)cnt++;
            else cnt--;

            if (cnt==k){
                cout <<
            }
        }


    }  


    return 0;
}
