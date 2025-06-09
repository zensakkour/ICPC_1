#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long  n, x, y, som=0;
        cin >> n >> x >> y;
        vector<long long > a(n, 0);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            som+=a[i];
        }
        sort(a.begin(), a.end());

        long long  res=0;
        for (long long i = 0; i < n - 1; i++) {
            long long mis=som-x;
            long long mxs=som-y;    
            auto itMIN=lower_bound(a.begin()+i+1,a.end(),mxs-a[i]);
            auto itMAX=upper_bound(a.begin()+i+1,a.end(),mis-a[i]);
            res+=max(static_cast<long long>(itMAX-itMIN),0LL);
        }
        cout <<res<<endl;
    }
    return 0;
}
