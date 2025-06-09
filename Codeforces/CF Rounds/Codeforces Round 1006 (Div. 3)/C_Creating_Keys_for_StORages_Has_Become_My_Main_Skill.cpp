#include <bits/stdc++.h>
using namespace std;


unsigned calcK(unsigned x) {
    for(int b = 0; b < 30; b++){
        if(((x >> b) & 1) == 0) return (1u << b); 
    }
    return (1u << 30);
}


int main(){
    int t; cin >> t;
    while(t--){
        long long n; 
        unsigned x;
        cin >> n >> x;
        if(n == 1){
            cout << x << "\n";
            continue;
        }

        unsigned K = calcK(x); 
        long long bestM = 0;
        bool needX =false;  

        auto rangeOR = [&](unsigned m){
            if(m ==0) return 0u;
            unsigned y = m - 1; 
            int hb = 31 - __builtin_clz(y);  
            unsigned mask = (1u << (hb+1)) - 1; 
            return mask;
        };

        long long start = min<long long>(n, K);

        for(long long m = start; m >=0; m--){
            unsigned partialOR = rangeOR((unsigned)m);
            if(partialOR == x){
                if(m <= n){
                    bestM = m;
                    needX = false;
                    break;
                }
            } else {

                if((unsigned)m <= x){ 
                    if(m+1 <= n){
                        bestM = m;

                        needX= true;
                        break;
                    }
                }
            }
        }
        vector<unsigned> ans;
        ans.reserve(n);
        for(unsigned i=0; i < (unsigned)bestM; i++)ans.push_back(i); 
        
        if(needX) ans.push_back(x);
        
        while((long long)ans.size() < n){
            ans.push_back(0);
        }
        for(int i=0; i<(int)n; i++){
            cout << ans[i] << (i+1<n?' ':'\n');
        }
    }
    return 0;
}