#include <bits/stdc++.h>
using namespace std;
using lli = long long;


int main(){

    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<lli> a(2*n);
        for (int i = 0; i < 2*n; i++){
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        
        lli sum = 0;
        for (int i = 2; i < 2*n; i += 2) sum +=a[i] - a[i+1];
        
        
        lli first = a[0];
        lli second = a[0] +a[1] - sum;
        
        cout << first << ' '<< second << ' ';
        
        for (int i = 1; i < 2*n; i++){
            cout << a[i] << ' ';
        }
        cout <<endl;
    }
    return 0;
}