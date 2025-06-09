#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2 == 0){
            for(int i = 1;i<=n/2;i++){
                cout << i << " " << i << " ";
            }
        }else{
            if(n<27){
                 cout << -1;
            }else{
                cout << "2 15 15 5 5 7 7 6 6 2 3 8 8 19 19 10 10 11 11 12 12 13 13 14 14 2 3 ";
                for(int i = 0;i< (n-27)/2;i++){
                    cout << 22 + i << " " << 22 + i << " ";
                }
            }

        }  
        cout << endl;
    }
    return 0;
}