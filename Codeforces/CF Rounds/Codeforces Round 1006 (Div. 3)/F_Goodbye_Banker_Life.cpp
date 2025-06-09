#include <bits/stdc++.h>
using namespace std;
using lli = long long;


static const int IO_BUF_SIZE = 1<< 20;
static char inbuf[IO_BUF_SIZE];
static char outbuf[IO_BUF_SIZE];


int main(){

    int t; cin >> t;
    while(t--){
        lli n, k; cin >>n >> k;
        long long mask =n - 1;  

        for(long long j = 0; j < n; j++){
            if((j & mask) == j )cout << k << ( (j+1 == n) ? '\n' : ' ' );
            else cout << 0 << ( (j+1 == n) ? '\n' : ' ' );
        }
    }
    return 0;
}