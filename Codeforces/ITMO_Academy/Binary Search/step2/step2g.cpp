#include<bits/stdc++.h>

using namespace std;

auto good(vector<long long> a, long long mid, long long k){
    long long slots = mid * k;
    for(auto i : a){
        slots -= min(mid, i);
    }        
    return slots <= 0;
    }

int main(){
    int n, k;cin >> k >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++)cin >> a[i];

    long long lw = 0, hi = *max_element(a.begin(), a.end()) * n + 1 , mid;

    while(lw + 1 < hi){
        mid = lw + (hi - lw)/2;
        if (good(a, mid, k)){
            lw = mid;
        }else hi = mid;
    }

    cout << lw <<endl;
    // cout << lw;
    return 0;
}