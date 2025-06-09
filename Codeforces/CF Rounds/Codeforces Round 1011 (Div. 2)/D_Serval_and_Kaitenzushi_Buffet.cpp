#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = 0;
    
    for(int i = n - k; i >= 1; --i){
        ll x = d[i-1];
        pq.push(x);
        ans += x;
        int rem   = n - i + 1;          
        int cap   = rem / (k + 1);    
        while((int)pq.size() > cap){
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}

int main(){


    int T; 
    cin >> T;
    while(T--) 
        solve();
    return 0;
}