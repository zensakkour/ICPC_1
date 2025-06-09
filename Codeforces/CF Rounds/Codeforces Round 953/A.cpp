#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin >>t;
    
    while(t--){
        int n, l;cin >>n;
        vector<int> v(n);
        for(int i=0;i < n - 1;i++){
            cin>>v[i];
        }
        cin >> l;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        cout << v[0] + l <<endl;

    }

    return 0;
}