#include <bits/stdc++.h>
using namespace std;
using lli = long long;
 
struct DP {
    lli A, B, C;
};
 
int main(){
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<char> opL(n+1), opR(n+1);
        vector<lli> parA(n+1),parB(n+1);

        for (int i = 1; i <= n; i++) cin >> opL[i] >> parA[i] >> opR[i] >> parB[i];
        
 
      
        vector<DP> dp(n+2);
        dp[n+1] = {1, 1, 0};
 
        for (int i = n; i >= 1; i--){
            char p = opL[i], q = opR[i];
            lli a = parA[i], b = parB[i];
            DP nxt = dp[i+1], cur;

            if(p == '+' && q == '+'){
                cur.A = nxt.A;
                cur.B =nxt.B;

                cur.C = nxt.C + max(nxt.A, nxt.B) * (a + b);
            }
            else if(p == 'x'&& q == '+'){
                if(nxt.A >= nxt.B){
                    cur.A = nxt.A * a;
                    cur.B = nxt.B;
                    cur.C= nxt.C + nxt.A * b;

                } else {
                    cur.A = nxt.A + nxt.B * (a - 1);
                    cur.B = nxt.B;
                    cur.C = nxt.C + nxt.B * b;
                }
            }
            else if(p == '+' && q == 'x'){

                if(nxt.A >= nxt.B){

                    cur.A = nxt.A;
                    cur.B = nxt.B + nxt.A * (b - 1);
                    cur.C = nxt.C + nxt.A * a;
                } else {
                    cur.A = nxt.A;
                    cur.B =nxt.B * b;
                    cur.C = nxt.C +nxt.B *a;
                }
            }
            else if(p == 'x' && q == 'x'){

                if(nxt.A >= nxt.B){
                    cur.A = nxt.A * a;
                    cur.B = nxt.B + nxt.A * (b - 1);
                    cur.C = nxt.C;
                } else {
                    cur.A = nxt.A + nxt.B* (a - 1);
                    cur.B = nxt.B * b;
                    cur.C = nxt.C;
                }
            }
            dp[i] = cur;
        }
 
       
        cout << dp[1].A+ dp[1].B + dp[1].C << endl;
    }
    return 0;
}
