#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli G(lli a, lli b){ 
    return b? G(b, a%b):a;}

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >>n;
        vector<lli> v(n);
        for(auto &x:v) cin >> x;

        lli m = *min_element(v.begin(), v.end());
        long long c = 0; for(auto &x: v) if(x == m) c++;
        if(c >= 2){ 
            cout << "Yes\n"; 
            continue; 
        }
        
        vector<lli> multiples;
        for(auto &x: v){
            if(x % m ==0 && x != m) multiples.push_back(x);
        }
        if(multiples.empty()){
            cout << "No\n";
            continue;
        }
        lli g = 0;
        for(auto &x: multiples)g = G(g, x);
        cout << (g == m ? "Yes\n": "No\n");
    }
}
