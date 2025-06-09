#include <bits/stdc++.h>
using namespace std;
 
const int INF = 100000000;
 
int n, m;
vector<vector<int>> A, B;
 
unordered_map<long long,int> mem;
 

 
long long keyF(int i, int act, int c) {
    
    return (((long long)i<<20) ^ ((long long)act<<16) ^ (c+10000));
}
 
int f(int i, int act, int c) {
    if(i==n) return 0;
    bool ok;
    long long key = keyF(i,act,c);
    if(mem.count(key)) return mem[key];
    int res = INF;
    if(!act){
        bool eq = true;
        for(int j=0;j<m;j++){
            if(A[i][j]!=B[i][j]) { eq=false; break; }
        }
        if(eq) res = min(res, f(i+1,0,0));
        bool ok = true;
        for(int j=1;j<m;j++){
            if(A[i][j-1]!=B[i][j]) { ok = false; break; }
        }
        if(ok){
            int nc = A[i][m-1];
            res = min(res, 1 + f(i+1,1,nc));
        }
    } else {
        vector<int> S(m);
        S[0] = c;
        for(int j=1;j<m;j++){
            S[j] = A[i][j-1];
        }
        
        bool eq = true;
        for(int j=0;j<m;j++){
            if(S[j]!=B[i][j]) { eq = false; break; }
        }
        if(eq){
            int nc = A[i][m-1];
            res = min(res, f(i+1,1,nc));
        }
        ok = true;
        for(int j=1;j<m;j++){
            if(S[j-1]!=B[i][j]) { ok = false; break; }
        }
        if(ok){
            int nc = S[m-1];
            res = min(res, 1 + f(i+1,1,nc));
        }
    }
    mem[key] = res;
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        A.assign(n, vector<int>(m));

        B.assign(n, vector<int>(m));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> A[i][j];
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> B[i][j];
            }
        }
        int first = -1;
        for (int i=0; i<n; i++){
            bool same = true;
            for (int j=0; j<m; j++){
                if(A[i][j]!=B[i][j]) { same = false; break; }
            }
            if(!same){ first = i; break; }
        }
        if(first==-1){
            cout << 0 << "\n";
            continue;
        }
        bool ok = true;
        for (int j=1; j<m; j++){
            if(A[first][j-1]!=B[first][j]) { ok = false; break; }
        }
        if(!ok){
            cout << -1 << "\n";
            continue;
        }
        mem.clear();
        int ans = 1 + f(first+1,1,A[first][m-1]);
        cout << (ans>=INF ? -1 : ans) << "\n";
    }
    return 0;
}
