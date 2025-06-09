#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n, 0);
        for(int i = 0;i < n;i++){
            cin >> p[i]; p[i]--;   
        }
        
        for(int i = 0;i < n ;i++){
            if(p[i] != i){
                if(p[i + 1] == i && p[i] == i + 1){
                    swap(p[i], p[i + 1]);
                }else{
                    cout <<" NO\n";
                    goto next;
                }
            }
            
        }

        cout <<"YES\n";
        next:;
        
    }
    return 0;
}