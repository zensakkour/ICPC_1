#include <bits/stdc++.h>
using namespace std;
using int64 = long long;


static inline void dedup(vector<int> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
int main() {
    int N;          
    int64 M;        
    if (!(cin >> N >> M)) return 0;
    vector<vector<int>> A(N, vector<int>(N));
    for (auto &row : A)
        for (int &x : row) cin >> x;
    if (N == 1) {                     
        cout << (A[0][0] % M) << '\n';
        return 0;
    }
    const int totalMoves = 2 * N - 2;
    const int L = totalMoves / 2;  

    const int R = totalMoves - L;     
    vector<int64> pow10(2 * N + 1, 1);
    for (int i = 1; i < (int)pow10.size(); ++i)
        pow10[i] = (pow10[i - 1] * 10) % M;
    vector pref(N, vector<vector<int>>(N));
    pref[0][0].push_back(A[0][0] % M);
    for (int step = 0; step < L; ++step) {
        vector nxt(N, vector<vector<int>>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int r : pref[i][j]) {
                    if (i + 1 < N)               
                        nxt[i + 1][j].push_back(
                            ( (int64)r * 10 + A[i + 1][j] ) % M );
                    if (j + 1 < N)               
                        nxt[i][j + 1].push_back(
                            ( (int64)r * 10 + A[i][j + 1] ) % M );
                }
        pref.swap(nxt);

    }
    for (auto &row : pref)
        for (auto &v : row) if (!v.empty()) dedup(v);
    vector suf(N, vector<vector<int>>(N));           
    vector cur(N, vector<vector<int>>(N));           
    cur[N - 1][N - 1].push_back(A[N - 1][N - 1] % M);   
    for (int moves = 0; moves < R; ++moves) {
        if (moves == R - 1) {                        
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    for (int v : cur[i][j]) {
                        if (i) suf[i - 1][j].push_back(v);  
                        if (j) suf[i][j - 1].push_back(v);  
                    }
        } else {
            int len = moves + 1;                     
            int64 mult = pow10[len];
            vector nxt(N, vector<vector<int>>(N));
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    for (int v : cur[i][j]) {
                        if (i) {                     
                            int d = A[i - 1][j];
                            int nv = ( (int64)d * mult + v ) % M;
                            nxt[i - 1][j].push_back(nv);
                        }
                        if (j) {                     
                            int d = A[i][j - 1];
                            int nv = ( (int64)d * mult + v ) % M;
                            nxt[i][j - 1].push_back(nv);
                        }

                    }
            cur.swap(nxt);
        }
    }
    for (auto &row : suf)
        for (auto &v : row) if (!v.empty()) { dedup(v); sort(v.begin(), v.end()); }
    const int64 powR = pow10[R];
    int64 answer = 0;

    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!pref[i][j].empty() && !suf[i][j].empty()) {
                const vector<int> &tail = suf[i][j];
                for (int P : pref[i][j]) {
                    int64 base = ( (int64)P * powR ) % M;
                    int64 need = M - 1 - base;           
                    auto it = upper_bound(tail.begin(), tail.end(),
                                          (int)need);
                    int64 best;
                    if (it != tail.begin()) {            
                        best = base + *(--it);
                    } else {                             
                        best = base + tail.back() - M;
                    }
                    answer = max(answer, best);
                }
            }
    cout << answer % M << '\n';
    return 0;
}