#include <bits/stdc++.h>
using namespace std;

long long  sum(const vector<long long> &v) {
  long long s = 0;
  for (auto &x: v)
    s += x;
  return s;
}

vector<long long> diffN(const vector<long long> &b) {
  int m = (int)b.size();
  vector<long long > c(m- 1);
  for (int i = 0; i + 1 < m; i++)
    c[i] = b[i +1] - b[i];
  return c;
}

vector<long long> diffR(const vector<long long> &b) {
  int m = (int)b.size();
  vector<long long> c(m - 1);
  for(int i=0;i+1<m;i++)
    c[i] = b[m-2 - i] - b[m-1 - i];
  return c;
}

int main() {
  
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i] ;

    if(n==1) {
      cout << a[0] << "\n";
      continue;
    }

    long long  best = sum(a);

    vector<long long> b = a;
    int len = n;
    while (len > 1) {
      long long  sB= sum(b);
      best = max(best, sB);
        auto cNormal = diffN(b);
        auto cReversed = diffR(b);

      long long sumN = cNormal.empty() ? 0LL :sum(cNormal);
      long long sumR = cReversed.empty( )? 0LL  : sum(cReversed);

      if (sumN >= sumR) {
        b = move(cNormal);
      } else {
        b =move(cReversed);
      }
      len--;
    }
    best = max(best, (long long)b[0]);

    cout << best <<"\n";
  }

  return 0;
}