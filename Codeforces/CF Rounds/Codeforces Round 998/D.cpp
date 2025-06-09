#include <bits/stdc++.h>
using namespace std;
int main(){
 int t;cin>>t;while(t--){
  int n;cin>>n;vector<long long> a(n);
  for(auto &x:a)cin>>x;
  long long s=a[0];
  bool f=1;
  for(int i=1;i<n;i++){
    if(a[i]<s){f=0; break;}
    s=a[i]-s;
  }
  cout<<(f?"YES":"NO")<<"\n";
 }
 return 0;
}
