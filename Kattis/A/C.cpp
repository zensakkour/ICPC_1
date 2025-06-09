#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C, Zr, Zc;
    cin >> R >> C >> Zr >> Zc;

    vector<string> article(R);
    for (int i = 0; i < R; ++i) {
        cin >> article[i];
    }

    for (int i = 0; i < R; ++i) {
        for (int zr = 0; zr < Zr; ++zr) {
            for (int j = 0; j < C; ++j) {
                for (int zc = 0; zc < Zc; ++zc) {
                    cout << article[i][j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}