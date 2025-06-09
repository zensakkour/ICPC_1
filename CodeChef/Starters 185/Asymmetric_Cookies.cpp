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
    int N;cin>>N;
    int c1=0,c2=0,c3=0;
    loop(i,0,N){
        int x; cin >> x;
        if( x == 1 ) c1++;
        else if(x==2) c2++;
        else c3++; 
    }
    int ans;
    if(c3>=3){
        ans = N;
    }else if(c3==2){
        ans = c1+c2+((c1&1)?0:2);
    }else if(c3==1){
        ans = (c1&1)?(c1+c2):1;
    }else{
        ans = (c1&1)?(c1+c2):0;
    }
    cout<<ans<< endl;
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