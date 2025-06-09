#include <bits/stdc++.h>
using namespace std;
 
inline bool has7(long long x) {
    while(x) { if(x % 10 == 7)return true; x /= 10; } 
    return false;
}
 
inline int digitSum(long long x) {
    int s=0; 
    while(x){ s+=x%10; x/=10; } 
    return s;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        if(has7(n)){
            cout<<0<<"\n";
            continue;
        }
        int ans=100;
        for(long long k=0; k<1000000LL; k++){
            int c = digitSum(k);
            if(c>=ans) continue;
            long long X = n + 9LL*k;
            if(has7(X)){
                ans = c;
                if(ans==1) break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
