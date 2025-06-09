#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // We do not know n, x[], or y[] in a real interactive setting:
    // The interactor "knows" them but does not reveal them.
    // We only know n, x[] from input, and we can query "? i j".
    
    // This is a sketch of how you would *attempt* in an interactive solve() function:

    // 1) We pick any distinct i, j (for example, i=1, j=2 if n>1).
    int i = 1, j = 2;

    // 2) Ask the first query: "? i j"
    cout << "? " << i << " " << j << endl;
    fflush(stdout);

    int d1;
    cin >> d1;  // read the answer from the interactor

    // 3) Ask the second query: "? j i"
    cout << "? " << j << " " << i << endl;
    fflush(stdout);

    int d2;
    cin >> d2;  // read the answer

    // 4) Apply the decision rules
    if (d1 == 0 || d2 == 0) {
        // BFS can yield 0 if no path, but Manhattan can never yield 0 for distinct points
        cout << "! A" << endl;
    }
    else if (d1 != d2) {
        // BFS (directed distance) can be asymmetric, Manhattan is always symmetric
        cout << "! A" << endl;
    }
    else {
        // d1 == d2 != 0 => consistent with Manhattan
        cout << "! B" << endl;
    }

    return 0;
}
