#include<bits/stdc++.h>

using namespace std;

long long f(long long x, long long w, long long h, long long n){
    return (x/w) * (x/h) >=n;
}

int main(){
    long long w, h, n;cin >> w >> h >> n;

    long long lw=-1, hi=1, mid;
    while(!f(hi,w,h,n))hi*=2;
    while(lw + 1 < hi){
        mid = (hi + lw)/2;

        if(f(mid,w,h,n)==1){ //f(hi)=1 && f(lw)=0
            hi = mid;
        }else lw = mid;
    }
    cout <<hi<<endl;



    return 0;
}