#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'
#define loop(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)

const int MOD = 1e9 + 7;
const int INF = 1e18;

const int MAXP = 6000000;      
const int NEED = 400000;      

vector<int> primes;            
vector<long long> primesPS;    

void build_primes() {
    vector<bool> is_comp(MAXP+1,false);
    primes.reserve(NEED+5);
    for(int i = 2; i <= MAXP && (int)primes.size() < NEED; ++i) {
        if (!is_comp[i]) {
            primes.push_back(i);
            if ((int)primes.size() == NEED) break;
            if ((long long)i * i <= MAXP) {
                for (int j = i*i; j <= MAXP; j += i)
                    is_comp[j] = true;
            }
        }
    }
    primesPS.resize(primes.size()+1);
    primesPS[0] = 0;
    for (int i = 0; i < (int)primes.size(); ++i) {
        primesPS[i+1] = primesPS[i] + primes[i];
    }
}

void solve() {
    int n; cin >> n;
    vi a(n);
    loop(i, 0, n){
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    vi ps(n);
    int p = 0;
    loop(i, 0, n){
        p += a[i];
        ps[i] = p;
    }
    int best = 0;
    for (int k = 0; k < n; ++k) {
        if (ps[k] >= primesPS[k+1]) {
            best = k+1;
        } else {
            break;  
        }
    }

    cout << (n - best) << '\n';

}

int32_t main() {
    build_primes();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}