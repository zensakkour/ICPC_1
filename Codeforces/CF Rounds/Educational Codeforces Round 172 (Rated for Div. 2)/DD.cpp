#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
const int INF = 4e18;

struct Seg {
    int l, r;
    bool operator<(const Seg& o) const {
        return l!=o.l ? l<o.l : r<o.r;
    }
};

void one_pass(const vector<Seg>& seg, vector<int>& ans) {
    int n = seg.size();
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    /* sort by (l ASC, r DESC) so predictors come first */
    sort(ord.begin(), ord.end(),
        [&seg](int i,int j){
            if (seg[i].l != seg[j].l)
                return seg[i].l < seg[j].l;
            return seg[i].r > seg[j].r;
        });

    set<int> bounds;                    // ordered multiset of r's
    for (int idx : ord) {
        auto it = bounds.lower_bound(seg[idx].r); // first r ≥ rᵢ
        if (it != bounds.end())
            ans[idx] += *it - seg[idx].r;         // add right expansion
        bounds.insert(seg[idx].r);                // i may predict others
    }
}

void solve() {
    int n;  cin >> n;
    vector<Seg> seg(n);
    for (int i=0;i<n;++i) cin>>seg[i].l>>seg[i].r;

    vector<int> ans(n,0);

    /* -------- pass 1 : expand to the RIGHT -------- */
    one_pass(seg, ans);

    /* -------- pass 2 : mirror, expand to the RIGHT again (i.e. left) -------- */
    vector<Seg> mir = seg;
    for (auto& s : mir) {
        s.l = -s.l;
        s.r = -s.r;
        swap(s.l, s.r);          // now l ≤ r still holds
    }
    one_pass(mir, ans);          // adds (lᵢ - Lmax)

    /* -------- identical intervals ⇒ answer 0 -------- */
    map<Seg,int> cnt;
    for (auto s: seg) cnt[s]++;
    for (int i=0;i<n;++i)
        if (cnt[seg[i]] > 1) ans[i] = 0;

    for (int x: ans) cout<<x<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;  cin>>T;
    while (T--) solve();
    return 0;
}
