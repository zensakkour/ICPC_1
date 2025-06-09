#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,a,b,c;cin>>n>>a>>b>>c;
        int sum=a+b+c;
        int res=n/sum;
        int sol=res*3;
        // cout <<sol<<" "<<res*sum<<" "<<res*sum+a<<endl;
        sol+=((res*sum<n)?1:0 )+ ((res*sum+a<n)?1:0) + ((res*sum+a+b<n)?1:0);
        cout<<sol<<endl;
    }
}