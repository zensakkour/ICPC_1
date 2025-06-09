#include<bits/stdc++.h>
using namespace std;
using lli = long long;


int main(){
    lli n, s;cin >> n >> s;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    lli sm = 0, l = 0, res = 0;
    for(int r = 0;r < n;r++){
        sm += a[r];
        while(sm > s){
            sm -= a[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res;

    return 0;
}