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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x +=0x9e3779b97f4a7c15ULL;
        x = (x^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x)const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin >> n;
    unordered_map<int,int,custom_hash> cnt;
    cnt.reserve(n *2);
    cnt.max_load_factor(0.7);

    vi a(n);
    for (int i= 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    for (auto &p: cnt)
        if (p.second >= 4) {
            cout<< "Yes\n";
            return;
        }

    vi days;
    days.reserve( cnt.size());
    for (auto &p :  cnt) days.push_back(p.first);
    sort(days.begin(),days.end());

    int m = (int)days.size();
    for (int l = 0; l < m; ) {
        int r = l;
        vi heavy;
        while (r < m && (r == l ||days[r] == days[r-1]+ 1)) {
            if (cnt[days[r]] >= 2) heavy.push_back(days[r]);
            ++r;
        }
        if (heavy.size()>= 2) {
            cout <<"Yes\n";
            return;
        }
        l = r;
    }

    cout <<"No\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
