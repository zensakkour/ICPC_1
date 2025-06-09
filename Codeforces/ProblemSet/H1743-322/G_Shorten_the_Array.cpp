#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* ch[2];
    int maxIdx;
    TrieNode() {
        ch[0] = ch[1] = nullptr;
        maxIdx = -1;
    }
};

void insertTrie(TrieNode* root, int x, int idx){
    auto node = root;
    node->maxIdx = max(node->maxIdx, idx);
    for(int b = 29; b >= 0; b--) {
        int bit = (x >> b) & 1;
        if (!node->ch[bit])
            node->ch[bit] = new TrieNode();
        node = node->ch[bit];
        node->maxIdx = max(node->maxIdx, idx);
    }
}

int queryTrie(TrieNode* root, int x, int k) {
    auto node = root;
    if (node->maxIdx == -1) return -1;

    int best = -1;
    for(int b = 29; b >= 0; b--) {
        int xb = (x >> b) & 1;
        int kb = (k >> b) & 1;
        int w  = xb ^ kb;

        if (kb == 1) {
            node = node->ch[w];
            if (!node) break;
        } else {
            if (node->ch[w^1])
                best = max(best, node->ch[w^1]->maxIdx);
            node = node->ch[w];
            if (!node) break;
        }
    }
    if (node) best = max(best, node->maxIdx);
    return best;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
        if (k == 0) {
            cout << 1 << "\n";
            return;
        }
    TrieNode* root = new TrieNode();
    int ans = INT_MAX;

    for(int i = 1; i <= n; i++) {
        if (i > 1) {
            int j = queryTrie(root, a[i], k);
            if (j != -1)
                ans = min(ans, i - j + 1);
        }
        insertTrie(root, a[i], i);
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
