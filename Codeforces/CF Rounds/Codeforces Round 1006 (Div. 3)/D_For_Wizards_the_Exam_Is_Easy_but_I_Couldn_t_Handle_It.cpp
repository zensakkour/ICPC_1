#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int bestL = 1, bestR = 1;
        int bestDelta =0;

        for (int l = 0; l< n; l++){
            int currD = 0;
            for (int r = l + 1; r< n; r++){

                if(a[r] > a[l]) currD++;
                else if(a[r] < a[l]) currD--;

                if(currD < bestDelta){
                    bestDelta = currD;
                    bestL = l + 1; 
                    bestR = r + 1;
                    
                }
            }
        }
        cout << bestL << " " << bestR << "\n";
    }
    return 0;
}