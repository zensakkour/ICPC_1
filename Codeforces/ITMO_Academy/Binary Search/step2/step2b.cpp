#include<bits/stdc++.h>

using namespace std;

bool f(double x, double k, vector<long long> v){
    double res=0;
    for(auto i : v)res += floor((i / x));
    return (res >= k);
}

int main(){
    long long n, k; cin >> n >> k;
    vector<long long> v(n);
    for(int i = 0;i < n;i++)cin >> v[i];

    long long mx=*max_element(v.begin(), v.end());
    double lw=0, hi=double(mx+1), mid;
    double cnt=0;
    while(hi - lw > 1e-7){
        mid = (hi + lw)/2.0;

        if(f(mid,k,v)==1){ //f(hi)=1 && f(lw)=0
            lw = mid;
        }else hi = mid;

        cnt++;
        if (cnt >= 1000)break;
    }
    cout <<setprecision(20)<<lw<<endl;



    return 0;
}