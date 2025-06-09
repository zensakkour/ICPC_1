#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        unordered_map<int, int> cm;

        for (int color : a) {
            cm[color]++;
        }
        int one = 0, other = 0;
        for (auto &entry : cm) {
            if (entry.second == 1) {
                one++;
            } else {
                other++;
            }
        }

        
        cout << ((one+1) / 2)*2 + other << endl;
    }
    return 0;
}
