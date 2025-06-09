#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        vector<int> cost(n*m + 1, 0);
        vector<bool> appears(n*m + 1, false);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int col = a[i][j];
                appears[col] = true;
                if (cost[col] == 0) cost[col] = 1;                 
                if (i > 0 && a[i - 1][j] == col)cost[col] = 2;
                if (j > 0 && a[i][j - 1] == col)cost[col] = 2;
            }
        }
        
        int mx = 0;
        long long res = 0;
        for (int col = 1; col <= n*m; col++){
            if (appears[col]){
                res += cost[col];
                mx = max(mx, cost[col]);
            }
        }
    
        cout << res - mx << endl;
    }
    
    return 0;
}
