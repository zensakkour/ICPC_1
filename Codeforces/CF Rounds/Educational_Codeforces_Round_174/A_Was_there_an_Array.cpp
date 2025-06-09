#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin >> t;
    while(t--){
        int n; cin >> n;

        vector<int> b(n - 2);

        for (int i = 0; i < n - 2; i++) cin >> b[i];
        
        vector<bool> f(n, false); 
        if(n - 2 >= 1 && b[0] == 1) f[1] = true;
        
        if(n - 2 >= 1 && b[n - 3] == 1) f[n - 1] = true;
        
        for (int i = 2; i <= n - 2; i++){
            if(b[i - 2] == 1 || b[i - 1] == 1){
                f[i] = true;
            }
        }
        bool p = true;
        for (int j = 0; j < n - 2; j++){
            if(b[j] == 0){
                int d_left = j + 1;   
                int d_right = j + 2;  
                if(f[d_left] && f[d_right]){
                    p = false;
                    break;
                }
            }
        }
        cout << (p ? "YES" : "NO") << "\n";
    }
    return 0;
}