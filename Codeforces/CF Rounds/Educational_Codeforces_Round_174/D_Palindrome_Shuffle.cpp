#include <bits/stdc++.h>
using namespace std;
using lli = long long;

bool check(string s, int mid, int n){
    vector<int> cnt(300);
    for(int i = 0; i < mid; ++i)
        cnt[s[i]]++;
    bool ok =true;

    for(int i = 0; i < min(n / 2, n - mid); ++i) {
        char c = s[n - i - 1];
        if (i < mid) {
            ok &= cnt[c] > 0;
            cnt[c]--;
        } else ok &= (c == s[i]);
        
    }
    return ok;
}



int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int i = 0, j = int(s.length()) - 1;
        while(s[i] == s[j]){
            if(j - i == 1)break;
            i++;
            j--;
        }
        if(j-i==1){
            cout << 0 <<endl;
            continue;
        }
        int n = s.length() - 2 * i;
        s = s.substr(i, n);
        // for(int i = 0;i < n;i++){
        //     cout << check(s,i,n)<<endl;
        // }
        int hi = n - 1, lw = 0, mid = lw + (hi - lw)/2, best = n - 1;
        while(lw <= hi){
            // cout << lw << " " << hi << endl;
            if(check(s,mid, n) == true){
                best = mid;
                hi = mid - 1;
            }else lw = mid + 1;
            mid = lw + (hi - lw)/2;
        }


        reverse(s.begin(), s.end());


        hi = n - 1, lw = 0, mid = lw + (hi - lw)/2;
        int best2 = n - 1;
        while(lw <= hi){
            // cout << lw << " " << hi << endl;
            if(check(s,mid, n) == true){
                best2 = mid;
                hi = mid - 1;
            }else lw = mid + 1;
            mid = lw + (hi - lw)/2;
        }
        cout << min(best,best2)  << endl;
    }
    return 0;
}

