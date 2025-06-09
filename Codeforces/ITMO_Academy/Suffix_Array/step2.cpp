#include <bits/stdc++.h>
using namespace std;

void radix_sort(vector<pair<pair<int, int>, int>>& a) {
    int n = a.size();
    {
        // Sort by the second key
        vector<int> cnt(n, 0);
        for (auto x : a) cnt[x.first.second]++;
        vector<int> pos(n, 0);
        for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
        vector<pair<pair<int, int>, int>> a_new(n);
        for (auto x : a) a_new[pos[x.first.second]++] = x;
        a = a_new;
    }
    {
        // Sort by the first key
        vector<int> cnt(n, 0);
        for (auto x : a) cnt[x.first.first]++;
        vector<int> pos(n, 0);
        for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
        vector<pair<pair<int, int>, int>> a_new(n);
        for (auto x : a) a_new[pos[x.first.first]++] = x;
        a = a_new;
    }
}

int main() {
    string s;
    cin >> s;
    s += '$';
    int n = s.length();
    vector<int> p(n), c(n);

    // k = 0 phase
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    }

    // Transitions of phases
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
        
    }

    // Output the suffix array
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout <<endl;
}
