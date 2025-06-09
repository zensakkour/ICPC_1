#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
        V[i] = V[i]-p;
    }

    int meh = 0, msf = 0;
    for (int i = 0; i < n; ++i) {

        meh = max(0, meh + V[i]);
        msf = max(msf, meh);
    }

    cout << msf << endl;

}
