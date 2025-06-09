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

void solve() {
    int N, M;
    cin >> N >> M;
    vi disliked_cnt(M);
    vector<vi> F(N+1);
    for (int d = 0; d < M; d++) {
        int K;
        cin >> K;
        disliked_cnt[d] = K;
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            F[x].pb(d);
        }
    }
    vi B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int edible = 0;
    vector<bool> used(N+1, false);
    for (int i = 0; i < N; i++) {
        int x = B[i];
        if (!used[x]) {
            used[x] = true;
            for (auto d : F[x]) {
                disliked_cnt[d]--;
                if (disliked_cnt[d] == 0) edible++;
            }
        }
        cout << edible << endl;
    }
}

int32_t main() {


    solve();
    return 0;
}
