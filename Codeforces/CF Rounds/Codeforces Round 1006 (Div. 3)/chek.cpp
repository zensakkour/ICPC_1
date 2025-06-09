#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Read number of test cases
    int T;
    cin >> T;
    vector<long long> K(T);
    
    // 2) Read K-values for each test
    for(int i = 0; i < T; i++){
        if(!(cin >> K[i])){
            cerr << "Error: not enough lines to read K for test " << (i+1) << "\n";
            return 1; // or exit(1)
        }
    }

    // 3) For each test, read the solution's output from stdin and check correctness
    for(int i = 0; i < T; i++){
        long long k = K[i];
        
        // First, read the integer n from the solution's output
        long long n;
        if(!(cin >> n)){
            cerr << "Error: not enough lines in solution output for test " << (i+1) 
                 << ". Expected 'n' but got EOF.\n";
            return 1;
        }
        
        // Check 0 <= n <= 500
        if(n < 0 || n > 500){
            cerr << "Test " << (i+1) << " ERROR: n = " << n 
                 << " is out of allowed range [0..500].\n";
            return 1;
        }

        // Now read n coordinates
        vector<pair<long long,long long>> pts(n);
        for(long long j = 0; j < n; j++){
            long long x, y;
            if(!(cin >> x >> y)){
                cerr << "Error: not enough lines for coordinates in test " << (i+1) 
                     << ". Expected " << n << " points, didn't get them.\n";
                return 1;
            }
            pts[j] = {x,y};
        }
        
        // Check all points are distinct
        {
            set<pair<long long,long long>> s(pts.begin(), pts.end());
            if((long long)s.size() < n){
                cerr << "Test " << (i+1) << " ERROR: Found duplicate coordinates.\n";
                return 1;
            }
        }

        // Count how many pairs (i,j) have x_i = x_j or y_i = y_j
        // This should be exactly k
        long long alignedPairs = 0;
        for(long long a = 0; a < n; a++){
            for(long long b = a+1; b < n; b++){
                // Condition for Euclidean distance == Manhattan distance:
                // either same x or same y
                if(pts[a].first == pts[b].first || pts[a].second == pts[b].second){
                    alignedPairs++;
                }
            }
        }

        // Compare with the required k
        if(alignedPairs != k){
            cerr << "Test " << (i+1) << " ERROR: Expected " << k 
                 << " aligned pairs, but got " << alignedPairs << ".\n";
            return 1;
        }

        // If we pass all checks for this test:
        cerr << "Test " << (i+1) << ": OK\n";
    }

    cerr << "All tests OK\n";
    return 0;
}
