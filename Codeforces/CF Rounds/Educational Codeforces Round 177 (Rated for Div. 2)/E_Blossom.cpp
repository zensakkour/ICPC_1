#include <bits/stdc++.h>
using namespace std;
using lli = long long;

static const int MOD = 1000000007;
static const int MAXN = 5000;
lli fact[MAXN+ 1] , invFact[MAXN+1];
lli modexp(lli base , int exp) {
    lli res = 1% MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp  >>= 1;
    }
    return res;
}

lli inv(lli x) {
    return modexp(x, MOD-2);
}
void buildFactorials( int n) {
    fact[0]  = 1; 
    for(int i=1; i<=n; i++){
        fact[i ]= fact[i-1]*i % MOD;
    }
    invFact[n] =inv(fact[n]);
    for(int i=n; i>= 1; i--){
        invFact[i -1]= (invFact[i]*i) % MOD;
    }
}
lli C(int n ,int k){
    if(k<0 || k>n) return 0;
    return fact[n ]*invFact[k]%MOD * invFact[n-k]%MOD;
}
int main(){

    buildFactorials(MAXN);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> pos(n, -1);  
        vector<bool> used(n,false);
        int missingCount = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i] >= 0){
                pos[a[i]] = i;
                used[a[i]] = true;
            } else {
                missingCount++;
            }
        }
        vector<int> missingVals;
        for(int x=0; x<n; x++){
            if(!used[x]) {
                missingVals.push_back(x);
            }
        }
        vector<int> prefMissing(n +1,0);
        for(int i=0; i<n; i++){
            prefMissing[i+1] = prefMissing[i] + (a[i]<0 ? 1:0);
        }
        vector<pair<int,int>> known;  
        known.reserve(n);
        for(int x=0; x<n; x++){
            if(pos[x] != -1){
                known.push_back({pos[x], x});
            }
        }
        sort(known.begin() , known.end()); 
        lli  subAnswer = 0;  
        vector<bool> isMissing(n,false);
        for(int x: missingVals) isMissing[x] = true;
        for(int L=0; L<n; L++){
            int iKnownLeft = int( lower_bound(known.begin(), known.end(), make_pair(L, -1)) - known.begin() );
            int iK = iKnownLeft; 
            set<int > insideXs;   


            int minPosBeforeL = int( lower_bound(known.begin(), known.end(), make_pair(L, 0)) - known.begin() );
            for(int R=L; R<n; R++){
                vector<int> insideKnown, outsideKnown; 
                for(auto &kv: known){
                    int idx = kv.first; 
                    int val = kv.second;
                    if(idx < L || idx > R) {
                        outsideKnown.push_back(val);
                    } else {
                        insideKnown.push_back(val);
                    }
                }
                sort(outsideKnown.begin( ) , outsideKnown.end());  
                sort(insideKnown.begin(), insideKnown.end());    
                int K_in = prefMissing[R+1]-prefMissing[L];
                int K_out = missingCount - K_in;
                int outMin = n;
                if(!outsideKnown.empty()){
                    outMin = outsideKnown[0];
                }
                lli segSum = 0;  
                for(int x =0; x<=outMin; x++){
                    if(x<outMin){

                        if(binary_search(insideKnown.begin(), insideKnown.end(), x)){
                            continue;
                        }
                        int cInLess = int(std::lower_bound(insideKnown.begin(), insideKnown.end(), x) - insideKnown.begin());
                        int need = x - cInLess;
                        if(need<0|| need>K_in) continue;
                        
                        bool banX =isMissing[x];
                        int freeCount = missingCount - need - (banX?1:0);
                        if(freeCount<0) continue;
                        
                        
                        lli ways = C(freeCount, K_in - need);
                        ways = (ways * fact[K_in]) % MOD;
                        ways = (ways * fact[K_out]) % MOD;
                        lli contrib = (1LL*x % MOD) * ways % MOD;
                        segSum = (segSum + contrib) % MOD;
                    }
                    else if(x==outMin){
                        if(x<n && binary_search(insideKnown.begin(), insideKnown.end(), x)){
                            continue;
                        }
                        int cInLess = (x<=n-1)
                          ? int(std::lower_bound(insideKnown.begin(), insideKnown.end(), x) - insideKnown.begin())
                          : int(insideKnown.size()); 
                        int need = x - cInLess;  
                        
                        if(need<0 || need>K_in) continue;
                        bool banX = (x<n && isMissing[x]);
                        int freeCount = missingCount - need - (banX?1:0);
                        
                        if(freeCount<0) continue;
                        
                        lli ways = C(freeCount, K_in - need);
                        ways= (ways * fact[K_in]) % MOD;
                        ways = (ways* fact[K_out]) % MOD;
                        lli contrib = (1LL*x % MOD) * ways % MOD;
                        segSum = (segSum + contrib) % MOD;
                    }
                }
                subAnswer = (subAnswer + segSum) % MOD;
            } 
        } 
        cout << subAnswer % MOD << "\n";
    }
    return 0;
}