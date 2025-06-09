#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


ll floor_root(ll n, int exp) {
    ll lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        long long power = 1;
        bool ok = true;
        for (int i = 0; i < exp; i++) {
            if (power > n / mid) { 
                ok = false; 
                break;
            }
            power *= mid;
        }
        if (ok && power <= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}
ll modMul(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a * b) % MOD;
}
ll sumRange(ll L, ll R) {
    ll inv2 = (MOD + 1) / 2; 
    auto S = [&](ll x) -> ll {
        return modMul(x, modMul(x + 1, inv2));
    };
    ll res = (S(R) - S(L - 1)) % MOD;
    if (res < 0) res += MOD;
    return res;
}
ll sumSquares(ll L, ll R) {
    auto S = [&](ll x) -> ll {
        ll inv6 = 166666668; 
        return modMul(x, modMul(x + 1, modMul(2 * x + 1, inv6)));
    };
    ll res = (S(R) - S(L - 1)) % MOD;
    if (res < 0) res += MOD;
    return res;
}
ll revInBase(ll n, ll p) {
    ll temp = n;
    vector<ll> digits;
    while (temp > 0) {
        digits.push_back(temp % p);
        temp /= p;
    }
    ll res = 0;
    for (ll d : digits) {
        res = modMul(res, p % MOD);
        res = (res + d) % MOD;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        if(k > n) {
            ll lower = max((ll)2, n + 1);
            if(lower <= k) {
                ll count = (k - lower + 1) % MOD;
                ans = (ans + modMul(n % MOD, count)) % MOD;
            }
        }
        for (int L = 2; ; L++){
            ll loP = floor_root(n, L) + 1;  
            ll hiP = floor_root(n, L - 1);    
            loP = max(loP, (ll)2);
            hiP = min(hiP, k);
            if(loP > hiP) {
                if(hiP < 2) break;
                continue;
            }
            if(L == 2){
                ll sumP = sumRange(loP, hiP);
                ll S1 = modMul(n % MOD, sumP);
                ll S2 = 0;
                ll pStart = loP;
                while(pStart <= hiP){
                    ll v = n / pStart; 
                    ll pEnd = min(hiP, n / v);
                    ll segSq = sumSquares(pStart, pEnd);
                    ll count = (pEnd - pStart + 1) % MOD;
                    ll seg = ((segSq - count) % MOD + MOD) % MOD;
                    S2 = (S2 + modMul(v % MOD, seg)) % MOD;
                    pStart = pEnd + 1;
                }
                ll contrib = (S1 - S2) % MOD;
                if(contrib < 0) contrib += MOD;
                ans = (ans + contrib) % MOD;
            } else {
                for (ll p = loP; p <= hiP; p++){
                    ll r = revInBase(n, p);
                    ans = (ans + r) % MOD;
                }
            }
            if(hiP < 2) break;
            if(loP > k) break;
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}