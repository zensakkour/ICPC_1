#include <bits/stdc++.h>
using namespace std;
using lli = long long;


int main(){
    int t; cin >> t;
    while(t--){
        lli k; cin >> k;
        if(k == 0){
            cout << 1 << "\n";
            cout << 0 <<" " << 0 << "\n";
            continue;
        }
        vector<int> rows;
        while(k > 0) {
            int m = 2;
            while((lli)m *(m - 1) / 2 <= k) {
                m++;
            }
            m--; 
            rows.push_back(m);
            k -= (lli)m * (m - 1) / 2;
        }


        int total_points = 0;
        for (int cnt : rows) total_points += cnt;
        cout << total_points << endl;
        int rowIndex = 0;
        for (int cnt : rows) {
            int base = 10000* rowIndex;
            int y = base; 

            for (int j = 0; j < cnt; j++) cout << base + j << " " << y << endl;
            

            rowIndex++;
        }
    }
    return 0;
}