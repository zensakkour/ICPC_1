#include <bits/stdc++.h>

using namespace std;

const long long T = 40000; 


long long gcdArray(vector<long long> arr, long long size) {
    if (size == 0) return 0;
    long long result = arr[0];
    for (long long i = 1; i < size; i++) {
        result = gcd(result, arr[i]);
         if (result == 1) break;
    }
    return result;
}


long long f(const long long TT,vector<long long> a,long long n) {
        bitset<T + 1> dp;
        dp[0] = 1; 
        for (long long i = 1; i <= n; ++i) {
            if (a[i] == 0) continue;

            for (long long j = TT; j >= 0; --j) {
                if (dp[j]) {
                    for (long long k = 1; k <= a[i] && j + k * i <= TT; ++k) {
                        dp[j + k * i] = 1;
                    }
                }
            }
        }

        long long count = dp.count();
        return count;
    }

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    long long maxres=0;
    
    vector<long long> numbers;
    long long realn=0;

    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i]!=0){
            realn++;
            numbers.push_back(i);}
        
    }
    
    long long GCD=gcdArray(numbers,realn);
    maxres=0;
    for (long long i = 1; i <= n; ++i) {
        a[i/GCD]=a[i];
        maxres+=a[i]*(i/GCD);
    }
    
    long long count=0;
    if(maxres>=T*2){
        count=f(T,a,n);
        count=count*2+maxres-2*T-1;
        
    }else{
        count=f(maxres,a,n);
    }
    


    cout << count << endl;

    return 0;
}
