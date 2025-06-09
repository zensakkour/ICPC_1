#include <bits/stdc++.h>
using namespace std;
int main(){

 int t; cin >> t;
 while(t--){

  int n; cin >> n;
  vector<vector<long long>> arr(n, vector<long long >(n));
  vector<long long> tot(n, 0);
  for (int i = 0; i < n; i++){
   long long s = 0;
   for (int j = 0; j < n;j++){
    cin >> arr[i][j];
    s += arr[i][j];
   }
   tot[i] = s;
  }
  vector<vector<bool>> avail(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++){
   long long sum = 0;
   
   for (int t = 0; t < n; t++){
    long long f = tot[i] - (sum + arr[i][t]);
    if(f < n)
     avail[(int)f][i] = true;
    sum += arr[i][t];
   }
  }

  int ans = 0;
  for (int k = n; k >= 1; k--){
   vector<vector<int>> graph(k);
   for (int d = 0; d < k; d++){
    for (int i = 0; i < n; i++){
     if(avail[d][i])
      graph[d].push_back(i);
    }
   }
   vector<int> match(n, -1);


   function<bool(int, vector<int>&)>dfs = [&](int d, vector<int> &vis) -> bool {
    for (int i : graph[d]){
     if(vis[i]) continue;

     vis[i] = 1;
     if(match[i] == -1 || dfs(match[i], vis)){
      match[i] = d;
      return true;
     }
    }
    return false;
   };


   int cnt = 0;
   for (int d = 0; d< k; d++){
    vector<int> vis(n,0);
    if(dfs(d, vis))
     cnt++;
   }
   if(cnt == k){
    ans = k;
    break;
   }
  }
  cout << ans << "\n";
 }
 return 0;
}
