#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    int t, h;cin >> t;
    while(t--){
        int n; cin>>n;

        vector<int>H(n);
        map<int,int>m;
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>h;

            m[h]++;
            mx=max(mx, m[h]);
        }

        cout<<n-mx<<endl;
}
    return 0;
}