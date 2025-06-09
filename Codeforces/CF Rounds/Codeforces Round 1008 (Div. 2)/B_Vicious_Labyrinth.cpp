#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int t;cin >> t;
    while(t--){
        lli n, k; cin >> n >> k;
        if(k%2 == 0){
            for(int i = 0;i < n-2;i++){
                cout << n-1 << ' ';
            }
            cout << n << ' ' << n-1 << endl;
        }else{
            for(int i = 0;i < n-2;i++){
                cout << n << ' ';
            }
            cout << n << ' ' << n-1 << endl;
        }
    }
    return 0;
}