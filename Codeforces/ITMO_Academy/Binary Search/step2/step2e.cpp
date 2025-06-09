#include<bits/stdc++.h>

using namespace std;

bool f(long double x, long double c){
    return (pow(x,2) + pow(x,0.5) ) >= c;
}

int main(){
    long double c; cin >> c;
    long double lw=0, hi= c, mid;
    
    // for(int i=0;i < 1000;i++){
    while((hi-lw)>1e-9){
        mid = (hi + lw) / 2.0;
        if(f(mid,c)==1){ //f(hi)=1 && f(lw)=0
            hi = mid;
        }else lw = mid;

    }
    cout <<setprecision(20)<<hi<<endl;
    return 0;
}