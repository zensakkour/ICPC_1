#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef long long ll;
int binomialCoeff_M_I(int n, int r){
    if (r > n)return 0;
    long long int m = 998244353;
    long long int inv[r + 1] = { 0 };
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;
    // Getting the modular inversion for all the numbers from 2 to r with respect to m
    for (int i = 2; i <= r; i++) inv[i] = m - (m / i) * inv[m % i] % m;
    int ans = 1;
    // for 1/(r!) part
    for (int i = 2; i <= r; i++) ans = ((ans % m) * (inv[i] % m)) % m;
    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (int i = n; i >= (n - r + 1); i--) ans = ((ans % m) * (i % m)) % m;
    return ans;
}
  

int main(){
    ll n;
    cin >>n;
    ll a,b,c,m,res=1;
    for(ll i=0;i<n/3;i++){
        cin >>a>>b>>c;
        m=1;
        if(a==b && a==c)m=3;
        else if(a==b || a==c){
            if(max(a,max(b,c))==a){m=1;}else{m=2;}
        }else if(b==c){
            if(max(a,max(b,c))==b){m=1;}else{m=2;}
        }else m=1;
    
        res=(res%mod*m%mod)%mod;
    }
    ll C=binomialCoeff_M_I(n/3,n/6)%mod;

    cout <<(C%mod*res%mod)%mod <<endl;


    return 0;
}