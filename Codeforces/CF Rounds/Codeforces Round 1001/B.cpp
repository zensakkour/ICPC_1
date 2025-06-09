#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        if (n==1 && a[0]<=1){
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for(int i=0; i<n; i++){
            long long gap = 2LL * max((long long)i, (long long)(n-1 - i));
            if(a[i] <= gap){
                ok = false;
                break;
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}
