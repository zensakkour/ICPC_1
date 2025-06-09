#include <bits/stdc++.h>
using namespace std;

void maximize_string(string& s) {
    int n = s.size();
    for (int i = 1; i < n;i++) {
        if (s[i] != '0' && s[i]-1 > s[i - 1]) {
            s[i] = s[i] - 1;
            swap(s[i], s[i - 1]);
            i = max(0, i - 2); 

        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        maximize_string(s);
        cout << s << endl;
    }
    
    return 0;
}
