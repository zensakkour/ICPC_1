#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >>r;

        vector<long long > a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        
        int k = r - l +1;
        
        vector<long long> pref;
        for (int i = 0;i < r; i++){
            pref.push_back(a[i]);
        }

        sort(pref.begin(), pref.end());

        long long ans1=0;
        for (int i = 0; i < k && i< (int)pref.size(); i++){
            ans1 += pref[i];
        }
 
        vector<long long> suff;
        for (int i = l - 1; i < n;i++){
            suff.push_back(a[i]);
        }
        sort(suff.begin(),suff.end());

        long long ans2= 0;
        for (int i= 0; i < k&& i <(int)suff.size();i++)ans2 += suff[i];
        
 
        cout << min(ans1, ans2) << "\n";
    }
    return 0;
}
