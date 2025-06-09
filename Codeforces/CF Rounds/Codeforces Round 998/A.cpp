#include <bits/stdc++.h>
using namespace std;
int f(int a1,int a2,int a3,int a4,int a5){
    int c=0;if(a3==a1+a2)c++;if(a4==a2+a3)c++;if(a5==a3+a4)c++;return c;}
    
    int main(){
        int t;cin>>t;
        while(t--){
            int a1,a2,a4,a5;cin>>a1>>a2>>a4>>a5;
            set<long long> s;
            long long x=a1+(long long)a2;
            long long y=a4-(long long)a2;
            long long z=a5-(long long)a4;
            s.insert(x);s.insert(y);s.insert(z);if(x==y&&y==z)s.insert(x);
            long long ans=0;for(auto &val:s)ans=max((long long)ans,(long long)f(a1,a2,val,a4,a5));
            cout<<ans<<"\n";}
            return 0;
            }
