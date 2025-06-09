#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m,L;cin >>n>>m>>L;
        vector<pair<int,int>> H;
        int l,r;
        for(int i=0;i<n;i++){
            cin>>l>>r;
            H.push_back(make_pair(l,r));
        }
        vector<pair<int,int>> P;
        priority_queue<int> pq;
        for(int i=0;i<m;i++){
            cin >>l>>r;
           P.push_back(make_pair(l,r));
        }
        int res=0,pow=1,i=0;
        for(auto c : H){
            
            while (i< P.size() && P[i].first<c.first){
                pq.push(P[i].second);
                i++;
            }
            while(pow<c.second -c.first +2){
                if (pq.empty()){res=-1;goto END;}
                pow+=pq.top();
                // cout <<"h "<<pq.top()<<endl;
                pq.pop();
                res++;
            }
        }
        END:
        cout <<res<<endl;
    }
    return 0;

}