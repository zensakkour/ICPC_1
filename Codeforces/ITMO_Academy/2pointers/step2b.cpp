#include<bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    int n;
    lli s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    lli sm = 0;
    int res=1e9;
    int l = 0;
    for(int r = 0;r < n;r++){
        sm += a[r];
        while(sm - a[l] >= s){
            sm -= a[l]; 
            l++;
        }
        if (sm >= s){
            res = min(res, (r - l + 1));
        }
    }
    cout << ((res == 1e9)? -1 : res);
    
}