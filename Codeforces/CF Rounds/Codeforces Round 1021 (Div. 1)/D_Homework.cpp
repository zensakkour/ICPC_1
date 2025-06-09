#include <bits/stdc++.h>
using namespace std;

static inline void ff(string &a, const string &b) {
    for (size_t i = 0; i < a.size(); ++i) a[i] = (a[i] == b[i] ? '0' : '1');
}

vector<string> gg(vector<string> v, int bits) {
    v.erase(remove_if(v.begin(), v.end(),
                      [](const string &s){ return s.find('1') == string::npos; }),
            v.end());
    sort(v.begin(), v.end());
    int r = 0;
    for (int piv = 0; piv < bits; ++piv) {
        int idx = -1;
        for (int i = r; i < (int)v.size(); ++i)
            if (v[i][piv] == '1') { idx = i; break; }
        if (idx == -1) continue;
        swap(v[r], v[idx]);
        const string &pivot = v[r];
        for (int i = 0; i < (int)v.size(); ++i)
            if (i != r && v[i][piv] == '1') ff(v[i], pivot);
        ++r;
    }
    v.resize(r);
    sort(v.begin(),v.end());
    return v;
}

struct DD {
    int block_len;
    vector<string> basis;
    bool operator==(const DD& o) const {
        return block_len == o.block_len && basis == o.basis;
    }
};

DD make_descriptor(const string &s) {
    int n = (int)s.size();
    if (n & 1) return { n, { s }};
    int m = n;
    while ((m & 1) == 0) m >>= 1;
    int block_len = m, blocks = n / block_len;
    if (block_len == 1) {
        bool has_one = (s.find('1') != string::npos);
        return { 1, has_one ? vector<string>{"1"} : vector<string>{} };
    }
    vector<string> vecs;
    vecs.reserve(blocks);
    for (int i = 0; i < blocks; ++i)
        vecs.emplace_back(s.substr(i* block_len, block_len));
    return { block_len, gg(move(vecs),block_len) };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;  cin >> tc;
    while (tc--) {
        int n;  string s, t;
        cin >> n >> s >> t;
        if (n & 1) {
            cout << (s == t ? "Yes\n": "No\n");
            continue;
        }
        int m = n;  while ((m & 1) == 0) m >>= 1;
        if (m == 1) {
            bool nz1 = (s.find('1')!= string::npos);
            bool nz2 = (t.find('1') != string::npos);
            cout << (nz1 == nz2 ? "Yes\n" : "No\n");
            continue;
        }
        cout << (make_descriptor(s)== make_descriptor(t) ?"Yes\n" : "No\n");
    }
    return 0;
}
