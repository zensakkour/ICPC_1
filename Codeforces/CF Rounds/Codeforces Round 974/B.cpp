#include<bits/stdc++.h>
using namespace std;
#define lli  long long

int main(){
    int t;cin >> t;
    while(t--){
        lli n, k;cin >> n >> k;
        if(int(ceil(n/2.0) - ceil((n-k)/2.0))%2==0)cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}