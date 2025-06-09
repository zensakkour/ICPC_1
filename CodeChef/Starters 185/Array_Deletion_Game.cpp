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

void solve(){
    int n; cin >> n;
    priority_queue<int,vector<int>, greater<int>> pq;
    long long s= 0;
    loop(i, 0 ,2 * n){
        int x; cin>>x;
        pq.push(x);
        s += x;
        int cap = (i+2)/2;
        if((int )pq.size( ) > cap){
            s -= pq.top();
            pq.pop();
        }
    }
    cout<<s<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}