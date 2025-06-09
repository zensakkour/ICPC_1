#include<bits/stdc++.h>

using namespace std;

bool f(long long s, long long x, long long y, long long n){
    long long res= 1;
    s-=min(x,y);
    res += floor(s / x);
    res += floor(s / y);
    return res >= n;
}

int main(){
    long long n, x, y; cin >> n >> x >> y;

    long long lw=0, hi= 2*1e9, mid;
    if(n == 1){
		cout << min(x,y);
        return 0;}
    while(lw + 1 < hi){
        mid = (hi + lw)/2;

        if(f(mid,x,y,n)==1){ //f(hi)=1 && f(lw)=0
            hi = mid;
        }else lw = mid;

        

    }

    cout <<hi<<endl;



    return 0;
}