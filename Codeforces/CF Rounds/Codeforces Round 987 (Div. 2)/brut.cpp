#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int n = 27;
    vector<int> v(n,0);
    v[0]=1;
    v[9]=1;
    v[25]=1;
    for(int i = 0;i < n;i++){
        cout << v[i] << " ";
    }
    return 0;
}