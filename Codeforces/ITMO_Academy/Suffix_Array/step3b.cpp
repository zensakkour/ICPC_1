#include <bits/stdc++.h>
using namespace std;

void radix_sort(vector<pair<pair<int, int>, int>>& a) {
    int n = a.size();
    {
        vector<int> cnt(n, 0);
        for (auto x : a) cnt[x.first.second]++;
        vector<int> pos(n, 0);
        for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
        vector<pair<pair<int, int>, int>> a_new(n);
        for (auto x : a) a_new[pos[x.first.second]++] = x;
        a = a_new;
    }
    {
        vector<int> cnt(n, 0);
        for (auto x : a) cnt[x.first.first]++;
        vector<int> pos(n, 0);
        for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
        vector<pair<pair<int, int>, int>> a_new(n);
        for (auto x : a) a_new[pos[x.first.first]++] = x;
        a = a_new;
    }
}

vector<int> suffix_array(string s) {
    int n = s.length();
    vector<int> p(n), c(n);

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
    return p;
}

int count_occurrences(const vector<int>& p, const string& s, const string& si) {
    int low = 0, high = p.size() - 1;

    // Find the lower bound
    int left = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        string substr = s.substr(p[mid], si.length());
        if (substr >= si) {
            left = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Find the upper bound
    low = 0, high = p.size() - 1;
    int right = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        string substr = s.substr(p[mid], si.length());
        if (substr > si) {
            high = mid - 1;
        } else {
            right = mid;
            low = mid + 1;
        }
    }

    if (left == -1 || right == -1 || left > right) {
        return 0;
    }
    return right - left + 1;
}

int main() {
    string s, si;
    cin >> s;
    s += '$';
    vector<int> p = suffix_array(s);
    int n;
    cin >> n;

    while (n--) {
        cin >> si;
        cout << count_occurrences(p, s, si) << endl;
    }

    return 0;
}
