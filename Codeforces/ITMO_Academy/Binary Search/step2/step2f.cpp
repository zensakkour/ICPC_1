#include<bits/stdc++.h>

using namespace std;

auto good(vector<long long> a, long long mid, string t, int n, string p){
    vector<bool> deleted(t.size(), false);
    for (long long i = 0; i < mid; i++) {
        deleted[a[i] - 1] = true; 
    }

    long long j = 0;
    for (long long i = 0; i < t.size(); i++) {
        if (!deleted[i] && t[i] == p[j]) {
            j++;
            if (j == p.size()) return true; 
        }
    }
    return j == p.size();
}

    int main(){
        string p, t;cin >> t >> p;
        long long n = t.size();
        vector<long long> a(n);
        for(int i=0;i < n;i++){
            cin >> a[i];
        }

        long long lw=0, hi=n-p.size()+1, mid;
        while(lw + 1 < hi){
            mid = lw + (hi - lw)/2;

            if(good(a, mid, t, n, p)){
                lw = mid;
            }else  hi = mid;
        }
        cout << lw;
        return 0;
    }