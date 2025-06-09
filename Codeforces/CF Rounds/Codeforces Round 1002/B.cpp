#include <bits/stdc++.h>
using namespace std;

int main(){


    int t; cin>> t;
    while(t--){
        int n,k; cin >>n >> k;
        vector<long long>a( n);
        for(auto &x:a) cin >> x;

        if(k == n){

            vector<long long > b;

            for(int i=1; i<n; i+=2){
                b.push_back(a[i]);
            }
            b.push_back(0 );

            int cost = 1;
            for(int i=0;i<(int)b.size(); i++){
                if(b[i] != i+1){
                    cost = i+1;
                    break;
                }
            }
            cout << cost << "\n";
            continue;
        }
        int Lmax = n - k/2;
        auto canCost1 = [&](){

            int limit= n - (k-1);

            for(int x=1;x<=limit; x++){
                if(a[x] !=1) return true;
            }
            return false;
        };


        function<bool(int)> canCostC = [&](int c){
            int need = 1;
            int i = 0;
            int sub = 1;
            
            int usedInB = 0;

            while(sub <= k && i < n && usedInB < c){

                int start = i;
                i++;
                if(sub % 2 == 1){

                    sub++;
                    continue;
                }

                usedInB++;
                if(usedInB < c){

                    if(a[start] == need){
                        need++;
                    } else {

                        return false;
                    }
                } else if(usedInB == c){

                    if(a[start] == c){
                        return false;
                    } else {


                        return true;
                    }
                }

                while(i < n && usedInB < c){

                    int nextPosInB = usedInB + 1;
                    if(nextPosInB < c){

                        if(a[i] == need){

                            need++;
                            usedInB++;
                            i++;
                        } else {


                            break;
                        }
                    } else if(nextPosInB == c){

                        if(a[i] == c){


                            break;
                        } else {

                            return true;
                        }
                    }
                }

                sub++;
            }


            if(usedInB < c){

                if(need == c) return true;
                else return false;
            }

            return false;
        };


        if(canCost1()){
            cout << 1 << "\n";
            continue;
        }

        int ans = -1;
        for(int c=2; c<=Lmax; c++){
            if(canCostC(c)){
                ans = c;
                break;
            }
        }
        if(ans < 0) ans = Lmax + 1;
        cout << ans << "\n";
    }

    return 0;
}