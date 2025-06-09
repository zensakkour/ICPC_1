#include<bits/stdc++.h>
using namespace std;

long long  nb, ns, nc;
long long  pb, ps, pc;
long long  b = 0,s = 0,c = 0;

bool good(long long  mid, long long  r) {
    long long req_b = max(0LL, 1LL * b * mid - nb);
    long long req_s = max(0LL, 1LL * s * mid - ns);
    long long req_c = max(0LL, 1LL * c * mid - nc);

    long long cost = req_b * pb + req_s * ps + req_c * pc;

    return cost <= r;
}


int main(){

    string recipe;cin >> recipe;

    for(auto st : recipe){
        if(st == 'B')b++;
        if(st == 'S')s++;
        if(st == 'C')c++;
    }

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    long long  r;cin >>r;

    long long  lw = 0, hi = max(nb,max(ns,nc)) * 3 + r * 3 + 1, mid;
    while(lw + 1 < hi){
        mid = lw + (hi - lw)/2;
        // cout << mid << " " << good(mid,r) << endl;
        if(good(mid, r)==1) lw = mid;
        else hi = mid;
    }

    cout << lw << endl;
    // cout << good(1,r);
    return 0;
}