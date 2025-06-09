#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


int main(){
    int t;cin >> t;
    while (t--) {
        long long n, m, q;cin >> n >> m >> q;
        vector<long long> a(q);
        vector<int>res;
        for (int i = 0; i < q; i++) {
            cin >> a[i];
            a[i]--;
        }
        
        pair<int,int> ps={m-1,m-1};
        pair<int,int> p0={-1000,-1000};
        pair<int,int> pf={-1000,-1000};
        bool done=false;

        for (int i = 0; i < q; i++) {
            
            if(a[i]<ps.first && ps.first!=p0.second+1)ps.first=max(0,ps.first-1);
            else if(a[i]>ps.second && ps.second!=pf.first-1)ps.second=min((int)n-1,ps.second+1);
            else if(done==false){
                done=true;
                p0.first=0;
                p0.second=0;
                if (ps.first==0)ps.first++;
                pf.first=m-1;
                pf.second=m-1;
                if(ps.second==m-1)ps.second--;    
            }
            if (done==true){
                if(a[i]>p0.second && p0.second <ps.first-1)p0.second=p0.second+1;
                if(a[i]<pf.first && pf.first>ps.second+1)pf.first=pf.first-1;
                
            }
            // if(pf.first==ps.second){
            //     res.push_back(((done==true && ps.first!=0)?1:0) + ((done==true && ps.second!=n-1)?1:0));
            // }else{

            
            
            // cout<<ps.first<<" "<<ps.second<<endl;
                
            
            // cout<<ps.second<<" "<<ps.first<<endl;
            // cout<<p0.second<<" "<<p0.first<<endl;
            // cout<<pf.second<<" "<<pf.first<<endl;
            int tmp=( (ps.first!=ps.second)? (ps.second-ps.first+1) :0) + ( (done==true)? (p0.second-p0.first +1) :0) + ( (done==true)? (pf.second-pf.first+1) :0);
            // cout <<tmp<<endl;

            
            res.push_back(tmp);

        }
        
        


        for (long long r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}