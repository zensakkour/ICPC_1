#include <bits/stdc++.h>
using namespace std;

vector<int> lcp;
vector<int> p;
vector<vector<int>>c;

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

    vector<int> tmp(n);
    // c.resize(n);

    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    tmp[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first)
            tmp[p[i]] = tmp[p[i - 1]];
        else
            tmp[p[i]] = tmp[p[i - 1]] + 1;
    }
    
    c.push_back(tmp);

    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{tmp[i], tmp[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        tmp[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first)
                tmp[p[i]] = tmp[p[i - 1]];
            else
                tmp[p[i]] = tmp[p[i - 1]] + 1;
        }
        k++;
        c.push_back(tmp);
        
    }

    // LCP Computation
    lcp.clear();
    lcp.resize(n - 1); 
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pi = c[k][i];

        if (pi > 0) { 
            int j = p[pi - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            
                lcp[pi - 1] = k;
        }
        if (k > 0) k--;
    }

}


bool custom_comp(pair<int,int> p1, pair<int,int>p2){
    
    auto [l1, r1]=p1;
    auto [l2, r2]=p2;
    int len1=r1-l1+1;
    int len2=r2-l2+1;
    int minlen=min(len1, len2);
    int k=0;
    while((1<<k) <=minlen)k++;
    k--;

    k=min(k,int(c.size()-1));
    pair<int, int> class1 = {c[k][l1 - 1], c[k][l1 + minlen - (1 << k) - 1]};
    pair<int, int> class2 = {c[k][l2 - 1], c[k][l2 + minlen - (1 << k) - 1]};

    bool res = false;
    if (class1 != class2) {
        res = class1 < class2;
    } else {
        if (len1 != len2) {
            res = len1 < len2;
        } else {
            res = p1 < p2;
        }
    }
    return res;
}

int main() {
    string s;cin >> s;
    vector<pair<int,int>> v;
    int t,l,r;cin>>t;
    while(t--){
        cin>>l>>r;
        v.push_back(make_pair(l,r));
    }
    s+="$";
    suffix_array(s);

    sort(v.begin(),v.end(),custom_comp);

    for(int i=0;i<v.size();i++){
        auto [l, r]=v[i];
        cout <<l<<" "<<r<<endl;;
    }

    return 0;
}
