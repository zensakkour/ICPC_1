#include <bits/stdc++.h>
using namespace std;

bool has7(long long x){
    while(x > 0){
        if(x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int main(){

    int t; cin >> t;
    while(t--){
        long long n;
        cin >> n;
        
        if(has7(n)){
            cout << 0 << "\n";
            continue;
        }
        string s = to_string(n);
        int L = s.size();

        vector<long long> blocks;
        long long cur = 9;
        for(int i = 1; i <=L; i++){
            blocks.push_back(cur);

            cur = cur * 10 + 9; 
        }

        long long limit = (long long)2 *(long long)pow(10LL, L + 1);

        queue<pair<long long ,int>> q;

        unordered_set<long long> visited;
        visited.insert(n);
        q.push({n, 0});

        int answer = -1;
        while(!q.empty()){
            auto [val, steps] = q.front();
            q.pop();

            for(int i = (int)blocks.size() - 1; i >= 0; i--){
                long long nxt = val + blocks[i];
            
                if(nxt >limit) continue;
                
                if(!visited.count(nxt)){
                    if(has7(nxt)){

                        answer = steps + 1;
                        break;
                    }

                    visited.insert(nxt);
                    q.push({nxt, steps + 1});
                }
            }
            if(answer != -1) break;
        }
        cout << answer << "\n";
    }
    return 0;
}