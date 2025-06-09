#include<bits/stdc++.h>
using namespace std;
using lli = long long;


int main(){
    int n, k; cin >> n >> k;
    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    map<lli, lli> m;
    lli cnt = 0, res = 0, l = 0;
    for(int r = 0;r < n;r++){
        if(m[a[r]]==0){
            cnt++;
        }
        m[a[r]]++;

        while(cnt > k){
            m[a[l]] -= 1;
            if (m[a[l]]==0)cnt--;
            l++;
        }
        res += r - l + 1;
    }
    cout <<res;
    return 0;
}