#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> a(n);
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }

        int target = sum / n; 

        long long b1 = 0, b2 = 0;  
        
        for (int i = 0; i < n; i++) {
            if(i % 2 == 0){
                a[i] += b1;
                b1 = a[i] - target;
            } else {
                a[i] += b2;
                b2 = a[i] - target;
            }
        }

        if (b1 < 0 || b2 < 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
