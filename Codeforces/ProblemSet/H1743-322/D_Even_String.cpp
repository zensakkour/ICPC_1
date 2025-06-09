#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 998'244'353;
 
int bpow(int x, int p){
	int res = 1;
	while(p){
		if (p % 2){
			res = (res * x) % MOD;
		}
		p >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}
 
int fact(int x){
	int res = 1;
	for (int i = 1; i <= x; i++){
		res = (res * i) % MOD;
	}
	return res;
}
 
void solve(){
	vector<int> c(26);
	for (int i = 0; i < 26; i++){
		cin >> c[i];
	}
 
	int s = accumulate(c.begin(), c.end(), 0ll);
	
	vector<int> dp(s + 1);
	dp[0] = 1;
 
	for (int i = 0; i < 26; i++){
		if (c[i] == 0){
			continue;
		}
		for (int j = s; j >= 0; j--){
			if (j + c[i] <= s){
				dp[j + c[i]] = (dp[j + c[i]] + dp[j]) % MOD;
			}
		}
	}
 
	int ans = dp[s / 2] * fact(s / 2) % MOD * fact((s + 1) / 2) % MOD;
	for (int i = 0; i < 26; i++){
		ans = (ans * bpow(fact(c[i]), MOD - 2)) % MOD;
	}
 
	cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}