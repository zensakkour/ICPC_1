#include<bits/stdc++.h>
using namespace std;
#define lli  long long

int main(){
    int t;cin >> t;
    while(t--){
        lli n, k;cin >> n >> k;
        vector<lli> a(n);
        for(int i = 0;i < n;i++){
            cin >>a[i];
        }
        lli gold = 0, cnt = 0;
        for(int i = 0;i < n;i++){
            if(a[i] >= k)gold += a[i];
            else if (a[i] == 0 && gold > 0) {
                gold--;
                cnt++;}
        }
        cout << cnt << endl;

    }
    return 0;
}