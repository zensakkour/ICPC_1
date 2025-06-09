#include <bits/stdc++.h>
using namespace std;
int main(){

 int t; 
 
 cin >> t;
 while(t--){

  int n, s1,s2; 
  cin >> n >> s1 >> s2;
  int m; 
  cin >> m;
  vector<vector<int>> g1(n+1), g2(n+1);
  for(int i = 0; i < m; i++){
   int a, b; 
   cin >> a >>b;
   g1[a].push_back( b);
   g1[b].push_back(a);
  }
  cin >> m;

  for(int i = 0; i < m; i++){

   int a, b; 
   cin >>a >> b;
   g2[a].push_back(b);
   g2[b].push_back(a);
  }


  vector<bool> good(n+1, false);
  vector<unordered_set<int>>st(n+1);


  for(int i = 1; i <= n; i++){
   for(auto x : g2[i])
    st[i].insert(x);
  }

  for(int i = 1; i <= n; i++){
   for(auto x : g1[i]){
    if(st[i].count(x )){
     good[i]= true;
     break;
    }
   }
  }
  const long long INF = 1LL << 60;


  vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
  dist[s1][s2] = 0;

  using state = pair<long long, pair<int,int>>;
  priority_queue<state, vector<state>, greater<state>> pq;

  pq.push({0, {s1,s2}});
  long long ans = -1;


  while(!pq.empty()){
   auto [cd, pr] = pq.top();
   pq.pop();
   int a = pr.first, b = pr.second;
   if(cd != dist[a][b])
    continue;
   if(a == b && good[a]){
    ans = cd;
    break;
   }
   for(auto na : g1[a])
    for(auto nb : g2[b]){
     long long nd = cd +abs((long long)na - nb);
     if(nd< dist[na][nb]){
      dist[na][nb]= nd;
      pq.push({nd, {na, nb}});
     }
    }
  }
  cout << ans << "\n";
 }
 return 0;
}
