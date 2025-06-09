#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define loop(i,a,b) for(int i=a,_b=b;i<_b;++i)

void solve() {
    int n, q;
    cin >> n >>q;
    vi b(n);
    loop(i,0,n) cin >>b[i];

    vector<array<int,3>> op(q);
    loop(i,0,q){
        int x, y, z;cin >> x >>y>> z;
        --x; --y;--z;
        op[i] = {x, y, z};
    }

    vi a = b;
    for(int i = q - 1; i >= 0; --i){
        auto [x,y,z] = op[i];
        a[x] = max(a[x], a[z]);
        a[y] = max(a[y], a[z]);
    }

    vi c = a;
    for(auto [x,y,z] : op){
        c[z] = min(c[x], c[y]);
    }

    if(c != b){
        cout << "-1\n";
        return;
    }

    loop(i,0,n)cout << a[i] << " ";
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
