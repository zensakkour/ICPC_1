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

struct Seg{
    int l, r;
    bool operator<(const Seg& o ) const{
        return l != o.l ? l < o.l : r < o.r;
    }
};

void one_pass(const vector<Seg>& seg, vector<int>& ans){
    int n = seg.size();
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&seg](int i, int j){
        if(seg[i].l != seg[j].l){
            return seg[i].l < seg[j].l;
        }
        return seg[i].r > seg[j].r;
    });

    set<int> bounds;
    for(int idx : ord){
        auto it = bounds.lower_bound(seg[idx].r);
        if(it != bounds.end()) ans[idx] += *it - seg[idx].r; 
        bounds.insert(seg[idx].r); 
    }

}

void solve() {
    int n; cin >> n;
    vector<Seg> seg(n);
    for(int i = 0;i < n; i++){
        cin >> seg[i].l >> seg[i].r;   
    }

    vector<int> ans(n,0);
    one_pass(seg, ans);

    vector<Seg> mir = seg;
    for(auto& s : mir){
        s.l = -s.l;
        s.r = -s.r;
        swap(s.l, s.r);
    }
    one_pass(mir, ans);

    map<Seg, int> cnt;
    for(auto s: seg)cnt[s]++;
    for(int i = 0; i < n; i++){
        if(cnt[seg[i]] > 1) ans[i] = 0;
    }
    for(int x : ans) cout << x << endl;

}

int32_t main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}