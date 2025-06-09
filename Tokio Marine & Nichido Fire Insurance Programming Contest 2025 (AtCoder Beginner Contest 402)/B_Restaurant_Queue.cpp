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

int32_t main() {


    int Q;
    cin >> Q;
    queue<int> que;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int X;
            cin >> X;
            que.push(X);
        } else {
            cout << que.front() << "\n";
            que.pop();
        }
    }

    return 0;
}
