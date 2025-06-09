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

const int MOD = 1e9 + 7;
const int INF = 1e18;


static const int MAXN = 200000 + 5;
static int sen[MAXN];

static int t = 1;

bool check(int x, int k, int n, const vi& a){
    if (x == 0) return n >= k;

    int have = 0, res = 0;
    ++t;
    int stamp = t;

    for (int i = 0; i < n; i++) {
        int v = a[i];
        if (v < x && sen[v] != stamp) {
            sen[v] = stamp;
            have++;
        }
        if (have == x) {
            res++;
            if (res >= k) return true;
            ++t;
            stamp = t;
            have = 0;
        }
    }
    return res >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int hi = n + 1, lw = 0;
    int mid;
    while(lw + 1 < hi){
        mid = (hi + lw)/2;
        if(check(mid, k, n, a) == true){ // lw == true
            lw = mid;
        }else{
            hi = mid;
        }
    }
    cout << lw << endl;
}

int32_t main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}