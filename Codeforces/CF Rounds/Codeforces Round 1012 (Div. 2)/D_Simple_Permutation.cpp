#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;


bool isPrime(int n) { 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; 
    return true; 
} 
  


vector<int> solve(int n, int p){
	vector<int> res;
	res.push_back(p);
	for(int i = 1 ;i <= n ;i++){
		if(p - i > 0) res.push_back(p - i);
		if(p + i <= n) res.push_back(p + i);
	}
	return res;
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> res;
		for(int x = 0 ; true; x++){
			if(isPrime(n / 2 + x)){
				res = solve(n , n / 2 + x);
				goto next;
			}
		}
        next :
		for(int i = 0 ; i < n ; ++i)
			cout << res[i] << " \n"[i == n - 1];
	}
	return 0;
}