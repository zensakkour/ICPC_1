#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin >>n;
        vector<int>a(n,0),b(n,0);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<n;i++){
            cin>>b[i];
        }

        for(int i=0;i<n-1;i++){
            a[i]=a[i]-b[i+1];
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(a[i]>0)res+=a[i];
        }
        cout<<res<<endl;
    }
    return 0;
}