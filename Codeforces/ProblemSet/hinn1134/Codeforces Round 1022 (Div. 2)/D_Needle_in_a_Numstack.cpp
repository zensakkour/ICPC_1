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
#define loop(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)

const int MOD = 1e9 + 7;
const int INF = 1e18;

int N, K, Q;
vi A, B;

inline int id(int p) {
    int r = (p - 1) % K;
    return (r < 0) ? r + K : r;
}

int ask(int p) {
    Q++;
    cout << "? " << p << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve() {
    cin >> N >> K;
    Q = 0;

    A.assign(K, 0);
    vector<int> T(K);
    for (int i = 0; i < K;++i) {
        A[i] = ask(i + 1);
    }

    for (int i = 0; i < K; ++i) {
        T[i] = ask(N - K + 1 + i);
    }

    int shift = -1;
    for (int s = 0; s < K; ++s) {
        bool ok = true;
        for (int j = 0; j < K; ++j) {
            if (T[(j + s) % K] == A[j]) { ok = false; break; }
        }
        if (ok) { shift = s; break; }
    }
    if (shift < 0) {
        cout << "! -1"<< endl;
        cout.flush();
        return;
    }

    B.assign(K, 0);
    for (int j = 0; j < K; ++j) {
        B[j] = T[(j + shift) % K];
    }

    int r = -1;
    loop(i, 0, K) {
        if (A[i] != B[i]) {
            r = i;
            break;
        }
    }

    if (r == -1) {
        cout << "! -1" <<endl;
        cout.flush();
        return;
    }

    int aVal = A[r];
    long long start = 1 + r;
    long long pB = N - ((N - start) % K);

    ask((int)pB);

    long long lo = 0;
    long long hi = (pB - start) / K;

    while (hi > 0 && ask((int)(start + hi * K)) == aVal) {
        --hi;
    }

    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (ask((int)(start + mid * K)) == aVal) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    long long pA = start + lo * K;
    long long boundary = -1;

    for (long long p = pA+ 1; p <= min<long long>(N, pA + K); ++p) {
        if (ask((int)p) != A[id((int)p)]) {
            boundary = p - 1;
            break;
        }
    }

    if (boundary < 0) {
        boundary = pA;
    }

    cout << "! " << boundary << " "<< (N - boundary) << endl;
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
