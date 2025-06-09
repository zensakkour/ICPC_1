#include <bits/stdc++.h>
using namespace std;

vector<int> lcp;
vector<int> p, c;

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

void suffix_array(string s) {
    int n = s.length();
    p.resize(n);
    c.resize(n);

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

    // LCP Computation
    lcp.clear();
    lcp.resize(n - 1); 
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];
        
        int j = p[pi - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[pi - 1] = k;
        if (k > 0) k--;
    }

}

int main() {
    string s;
    cin >> s;
    s += '$';
    suffix_array(s);

    // for (int i = 0; i < s.length(); i++) cout << p[i] << " ";
    // cout << endl;
    // for (int i = 0; i < s.length() - 1; i++) cout << lcp[i] << " ";

    int n=s.length();
    long long res=0;
    
    for(int i=1;i<n;i++){
        res+=(n-p[i]-1)-lcp[i-1];
    }
    cout<<res<<endl;
    return 0;
}
