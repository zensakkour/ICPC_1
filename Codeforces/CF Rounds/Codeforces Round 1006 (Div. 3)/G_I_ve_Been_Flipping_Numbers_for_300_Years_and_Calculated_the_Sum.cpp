#include <bits/stdc++.h>
using namespace std;
using lli = long long;

static const lli MOD = 1000000007;
static const int MAXN = 300000;  
static lli prefix1[MAXN+1];
static lli prefix2[MAXN+1];


lli revSlow(lli n, lli p){
    lli result = 0;
    lli pm = p %MOD;
    while(n > 0){

        lli d = n % p;
        n/= p;
        result = (result * pm + d) % MOD;
    }
    return result;
}


void buildPrefixSums(){
    lli sum1 = 0, sum2 = 0;
    for(int i=1; i<=MAXN; i++){
        sum1 = (sum1 +i) % MOD;
        sum2 = (sum2 + 1LL*i*i) % MOD;
        prefix1[i] =sum1;
        
        prefix2[i] = sum2;
    }
}


inline lli rangeSum1(int L,int R){
    if(R < L) return 0;

    lli s = prefix1[R] - (L==0?0: prefix1[L-1]);
    return (s%MOD + MOD) %MOD;
}

inline lli rangeSum2(int L, int R){
    if(R < L) return 0;
    lli s = prefix2[R] - (L==0?0: prefix2[L-1]);
    return (s%MOD + MOD) % MOD;
}
int main(){
    buildPrefixSums();  
    int t; cin >> t;
    while(t--){
        lli n,k; cin >> n >> k;
        lli m = min(n,k);
        if(n == 1){
            lli ans = 0;
            if(k >= 2){
                lli diff = (k-1) % MOD; 
                ans =diff; 
            }
            cout << ans << "\n";
            continue;
        }

        lli sumRev = 0;
        lli sq = (lli)floorl(sqrtl((long double)n));
        lli endA = min(m, sq);
        for(lli p=2; p <= endA; p++) sumRev = (sumRev + revSlow(n,p)) % MOD;
        

        if(endA < m){
            lli pStart = endA +1;
            if(pStart <= n){

                lli pEnd = min(m, n);

                while(pStart <= pEnd){
                    lli A = n / pStart;  
                    if(A == 0) break;
                    
                    lli pMax = n / A; 
                    if(pMax > pEnd) pMax = pEnd; 
                    if(A < pStart){
                        lli count = pMax - pStart + 1;

                        lli s1 =rangeSum1((int)pStart, (int)pMax);   
                        lli s2 = rangeSum2((int)pStart, (int)pMax);   
                        lli term = 0;
                        {
                            lli tmp = (n % MOD) * (s1 % MOD) % MOD;
                            term = (term + tmp) % MOD;
                        }

                        {
                            lli tmp = (A% MOD) * (s2 % MOD) % MOD;
                            term = (term - tmp) % MOD;
                        }
                        {
                            lli tmp = (A % MOD) * (count% MOD) % MOD;
                            term = (term + tmp)% MOD;
                        }
                        sumRev = (sumRev + term) % MOD;
                    }
                    pStart = pMax + 1;
                }
            }
        }
        if(k >n){
            lli diff = ((k%MOD) - (n%MOD) + MOD) % MOD;
            lli bigPart = ( (n%MOD) * diff ) % MOD;
            sumRev = (sumRev + bigPart) % MOD;
        }
        lli ans = (sumRev % MOD + MOD) % MOD;
        cout << ans <<endl;
    }
    return 0;
}