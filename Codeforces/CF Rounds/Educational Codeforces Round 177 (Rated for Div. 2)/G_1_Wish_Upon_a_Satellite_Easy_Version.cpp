#include<bits/stdc++.h>
using namespace std;
using lli = long long;
using Un_lli = unsigned long long;
static const int LIMIT=10;
unordered_map< Un_lli , lli > memoG;


Un_lli getH(const vector<int>& v , bool turn ){
    Un_lli H=1469598103934665603ULL;
    for(auto &x : v){
        H^=(Un_lli)x; 
        H*=1099511628211ULL;
    }
    H^=(Un_lli)turn; 
    H*=1099511628211ULL;
    return H;
}


lli goMinMax(vector<int> &v , bool t){
    if(v.size()==1)return v[0];
    Un_lli k = getH(v,t);
    if(memoG.count(k))return memoG[k];
    if(!t){
        lli ans=-1000000000000000000LL;
        for(int i=0; i+1<(int)v.size(); i++){
            int m = min(v[i],v[i+1]);
            vector<int> w; w.reserve(v.size()-1);
            for(int j=0; j<(int)v.size(); j++){
                if(j==i){ w.push_back(m); j++; }
                else w.push_back(v[j]);
            }
            ans = max(ans, goMinMax(w,true));
        }
        memoG[k] = ans; 
        return ans;
    } else {
        lli ans=1000000000000000000LL;
        for(int i=0; i+1<(int)v.size(); i++){
            int m = max(v[i],v[i+1]);
            vector<int> w; w.reserve(v.size()-1);
            for(int j=0; j<(int)v.size(); j++){
                if(j==i){ w.push_back(m); j++; }
                else w.push_back(v[j]);
            }
            ans = min(ans, goMinMax(w,false));
        }
        memoG[k]=ans; 
        return ans;
    }
}


lli fallback(const vector<int> &vec ){
    vector<int> w=vec; bool t=false;
    while(w.size()>1){
        if(!t) w[0]= min(w[0],w[1]);
        else   w[0] = max(w[0],w[1]);
        w.erase(w.begin()+ 1); 
        t=!t;
    }
    return w[0];
}


lli totalVal(const vector<int>& a){
    memoG.clear();
    lli tot=0; 
    int n=a.size( );
    for(int i=0;i<n;i++){
        for(int j=i; j<n;j++){
            int len=j-i+1;
            if(len== 1) tot+=a[i];
            else if(len<=LIMIT){
                vector<int> sub; 
                sub.reserve(len);
                for(int k=i;k<=j;k++) sub.push_back(a[k]);
                tot+= goMinMax(sub,false);
            } else {
                vector<int> sub; 
                sub.reserve(len);
                for(int k=i;k<=j;k++) sub.push_back(a[k]);
                tot +=fallback(sub);
            }
        }
    }
    return tot;
}


int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int>arr(n ); 
        vector<bool>  used(n+1,false);
        for(int i=0;i<n;i++){
            cin>> arr[i];
            if(arr[i]) used[arr[i]]=true;
        }
        
        vector<int> miss;
        for(int x=1;x<=n;x++){
            if(!used[x]) miss.push_back(x);
        }
        vector<int> zeros;
        for(int i=0;i<n;i++){
            if(!arr[i]) zeros.push_back(i);
        }

        if((int)zeros.size()<=8){
            lli best=-1000000000000000000LL;
            sort(miss.begin(),miss.end());
            do{
                vector<int> temp=arr;
                for(int i=0;i<(int)zeros.size();i++){
                    temp[ zeros[i] ]= miss[i];
                }
                best=max(best,totalVal(temp));
            }while(next_permutation(miss.begin(),miss.end()));
            cout<< best<< "\n";
        } else {

            sort(miss.begin() ,miss.end(),greater<int>());
            vector<int>  temp= arr;
            for(int i=0; i<(int)zeros.size();i++){
                temp[ zeros[i] ]= miss[i];
            }
            cout<< totalVal(temp)<<"\n";
        }
    }
    return 0;
}
