#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'
#define loop(i,a,b) for(int i=(a), _b=(b); i<_b; ++i)

const int INF = 4e18;

// Check if we can build k disjoint pairs (value 1..k) and compute their total distance
auto n = [](const vector<vector<int>>& pos, int n, int k, long long &dist)->bool{
    multiset<int> S;               // ordered indices currently "alive"
    long long tot = 0;
    for(int v = n; v >= 1; --v){
        for(int idx : pos[v]) S.insert(idx); // indices whose a_i == v now become available (since we process v descending)
        if(v <= k){                           // we must create a pair for value v
            if(S.size() < 2) return false;    // not enough indices -> infeasible
            int l = *S.begin();
            int r = *S.rbegin();
            tot += r - l;                     // add distance
            S.erase(S.begin());
            auto it = S.end(); --it;          // iterator to last element after previous erase
            S.erase(it);                      // remove r
        }
    }
    dist = tot;
    return true;
};

void solve(){
    int n; cin >> n;
    vector<vector<int>> pos(n+1);
    loop(i,1,n+1){
        int x; cin >> x;
        pos[x].pb(i);           // store positions for each value
    }

    int lo = 0, hi = n/2, best_k = 0; // maximum number of pairs we can realise
    long long best_sum = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        long long cur = 0;
        if(feasible(pos, n, mid, cur)){
            best_k = mid;
            best_sum = cur;
            lo = mid + 1; // try more pairs
        }else hi = mid - 1;
    }
    cout << best_sum << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
