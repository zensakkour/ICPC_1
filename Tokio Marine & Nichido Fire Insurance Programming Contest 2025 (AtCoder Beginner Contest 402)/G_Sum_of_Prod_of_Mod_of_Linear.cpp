#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi2")

#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using i128= __int128_t;


static inline ll S1(ll n) { return n*(n-1)/2; }
static inline ll S2(ll n) { return n*(n-1)*(2*n-1)/6; }

int main(){
    int T;
    if (scanf("%d",&T)!=1) return 0;
    while (T--){
        ll N,M,A,B1,B2;
        scanf("%lld%lld%lld%lld%lld",&N,&M,&A,&B1,&B2);

        
        ll g= gcd(A,M);
        ll P= M/g;
        ll r1= B1 % g, r2= B2 % g;

  
        ll b1= ((B1 - r1)/g) % P; if (b1<0) b1+=P;
        ll b2= ((B2 - r2)/g) % P; if (b2<0) b2+=P;
        ll step= (A/g) % P;         if (step<0) step+=P;
        ll d = (b2 - b1 + P) % P;


        ll sumS = S1(P);
        ll sumProd= (d==0? S2(P): S2(P-d) + d*S1(P-d)+ S2(d) + (P-d)*S1(d));

        i128 period= (i128)g*g * sumProd+ (i128)g*r1 * sumS+ (i128)g*r2 * sumS+ (i128)r1*r2 * P;

        ll q= N / P;
        ll rem= N % P;
        i128 ans= period * q;

     
        ll sum_s1= 0, sum_s2= 0;
        i128 sum_s12= 0;
        uint32_t _P = (uint32_t)P;
        uint32_t _d= (uint32_t)d;
        uint32_t _step= (uint32_t)step;
        uint32_t s = (uint32_t)b1;

        int n4= rem >> 2;
        while (n4--){
            for (int rep= 0; rep < 4; ++rep){
                uint32_t t = s + _d;
                uint32_t mask= -(t >= _P);
                uint32_t s2= t - (mask & _P);
                sum_s1+= s;
                sum_s2  +=s2;
                sum_s12+= (uint64_t)s * s2;
                t =s + _step;
                mask= -(t >= _P);
                s = t - (mask & _P);
            }
        }
        for (int i= rem & 3; i--; ){
            uint32_t t = s + _d;
            uint32_t mask= -(t >= _P);
            uint32_t s2= t - (mask & _P);
            sum_s1  += s;
            sum_s2  += s2;
            sum_s12 += (uint64_t)s * s2;
            t = s + _step;
            mask= -(t >=  _P);
            s = t -(mask & _P);
        }

        ans += (i128)g*g  * sum_s12+ (i128)g*r2 * sum_s1+ (i128)g*r1 * sum_s2 + (i128)rem * r1 * r2;

        printf("%lld\n", (long long)ans);
    }
    return 0;
}
