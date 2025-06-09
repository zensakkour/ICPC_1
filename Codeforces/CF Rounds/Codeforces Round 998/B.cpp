#include <bits/stdc++.h>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){

        int n,m; cin>>n>>m;

        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>v[i][j];
            sort(v[i].begin(),v[i].end());
        }
        
        vector<vector<int>> comp(n,vector<int>(n,0));
        bool bad=false;
        for(int i=0;i<n && !bad;i++){
            for(int k=i+1;k<n && !bad;k++){
                bool ik=true,ki=true;
                for(int j=0;j<m;j++){
                    if(v[i][j]>=v[k][j]) ik=false;
                    if(v[k][j]>=v[i][j]) ki=false;
                    if(!ik && !ki) break;
                }
                if(!ik && !ki){bad=true;break;}
                if(ik){comp[i][k]=1;comp[k][i]=-1;}
                else {comp[i][k]=-1;comp[k][i]=1;}
            }
        }
        if(bad){cout<<"-1\n";continue;}
        
        vector<int> order; order.reserve(n);
        for(int i=0;i<n;i++){
            order.push_back(i);
            int pos=(int)order.size()-1;
            while(pos>0 && comp[order[pos]][order[pos-1]]==1){
                int tmp=order[pos];order[pos]=order[pos-1]; order[pos-1]=tmp;
                pos--;
            }
        }
        bool ok=true;
        for(int j=0;j<m-1;j++){
            if(v[order[n-1]][j]>=v[order[0]][j+1]){ok=false;break;}
        }
        if(!ok){cout<<"-1\n";
        continue;}
        for(int i=0;i<n;i++) cout<<order[i]+1<<(i+1<n?' ':'\n');
    }
    return 0;
}
