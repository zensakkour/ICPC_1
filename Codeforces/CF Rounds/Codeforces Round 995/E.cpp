#include <bits/stdc++.h>
using namespace std;

typedef long long ll;




ll BS(const vector<ll>& v, ll p) {
    ll lw = 0, hi = v.size() - 1;
    ll mid;
    while (lw <= hi) {
        mid = lw + (hi - lw) / 2;
        if (v[mid]>=p){
            hi=mid-1;
        }else lw=mid+1
    }
    return v.size() - lw;  
}

int main() {
    ll t;cin >> t;

    while (t--) {
        ll n, k;cin >> n >> k;
        set<ll> PP;

        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];PP.insert(a[i]);
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];PP.insert(b[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());


        ll res = 0;

        for (ll p : PP) {
            ll trees_bought = BS(b, p);  
            ll neg_rev = trees_bought - BS(a, p); 

            if (neg_rev <= k) {
                res = max(res, trees_bought*p);
            }
    }

        cout << res << endl;
    }
    return 0;
}
