#include <bits/stdc++.h>
using namespace std;
using lli = long long;

auto f(int i, lli x){

    return 0;
}

int main(){
    int t;cin >> t;
    while(t--){
        lli n; cin >> n;
        lli cnt = 0;
        if(n>15){
            cnt += n/15 * 3;
            for(int i = n-n%15; i <=n ;i ++){
                if(i%3 == i%5)cnt ++;
            }


        }else{
            cnt = 0;
            for(int i = 0 ; i <=n ;i++){
                if(i%3 == i%5)cnt ++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}