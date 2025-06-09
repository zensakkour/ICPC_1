#include <bits/stdc++.h>
using namespace std;
using lli = long long;


int main(){

    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> A(n+1 ),B(n+1);
        for (int i = 1; i <= n; i++) cin >> A[i];
        
        for (int i = 1; i <= n; i++)cin >> B[i];
        
        unordered_map<lli, vector<int>> buckets;
        buckets.reserve(n*2);

        int mod = n+ 1; 
        for (int i = 1; i <= n; i++){
            lli key = (lli)A[i] * mod + B[i];
            buckets[key].push_back(i);
        }
        bool possible = true;
        vector<pair<int,int>> mirrorPairs; 
        int leftover = -1; 
        for(auto &entry : buckets){
            lli key = entry.first;
            int x = key / mod;
            
            int y= key % mod;
            
            if(x == y){
                int cnt = entry.second.size();
                if(n % 2 == 0){
                    if(cnt % 2 != 0){ possible = false;break; }
                } else {

                    if(cnt % 2 != 0){
                        if(leftover == -1){
                            leftover = entry.second.back();
                            entry.second.pop_back( );
                            cnt--;
                        } else {
                            possible= false; break;
                        }
                    }
                }
                for (int i = 0; i <cnt; i += 2){
                    mirrorPairs.push_back({ entry.second[i], entry.second[i+1] });
                }
            } else {
                if(x < y){

                    lli mirrorKey = (lli)y * mod + x;
                    if(buckets.find(mirrorKey) == buckets.end()){
                        possible = false; break;
                    }
                    if(buckets[key].size() != buckets[mirrorKey].size()){
                        possible = false; break;
                    }

                    auto &vec1 =entry.second;
                    auto &vec2 = buckets[mirrorKey];
                    int sz = vec1.size();
                    for (int i = 0; i <sz; i++){
                        mirrorPairs.push_back({ vec1[i], vec2[i] });
                    }
                }
            }
        }
        if( (int)mirrorPairs.size()*2 + (n % 2) != n )
            possible = false;
        if(!possible){
            cout << -1 << "\n";
            continue;
        }

        vector<int> F(n+1,0);
        int Lpos = 1;
        int Rpos = n;
        for(auto &pr : mirrorPairs){
            F[Lpos++] = pr.first;

            F[Rpos--] = pr.second;
        }

        if(n % 2 == 1) F[(n+1)/2] = leftover;
        
        vector<int> curr(n+1);
        for (int i = 1; i <= n; i++){
            curr[i] = i;
        }

        vector<int> pos(n+1);
        for (int i = 1; i <= n; i++) pos[i] = i;
        

        vector<pair<int,int>> ops;
        for (int i = 1; i <= n; i++){
            if(curr[i] != F[i]){
                int j = pos[F[i]];
                swap(curr[i],curr[j]);
                pos[curr[i]] = i;
                pos[curr[j]] = j ;
                ops.push_back({i, j});
            }
        }
        cout << ops.size() <<"\n";
        for(auto &op :ops){
            cout << op.first <<" " << op.second << "\n";
        }
    }
    return 0;
}