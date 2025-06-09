#include <bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        long long l,r;
        cin>>l>> r;
        if(l ==r){
            cout<<(l==1?1:0)<<"\n";
            
            continue;
         }
        long  long ans=0;
        if(l<= 1 && r>=1) ans++;
   
        long  long start=max(l,2LL);
        if(start <=r-1) ans+= (r-1 - start +1);
        cout <<ans<<"\n";
    }
    return 0;
}
