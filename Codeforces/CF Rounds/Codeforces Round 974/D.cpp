#include <bits/stdc++.h>
using namespace std;
struct Z{int l,r,id;};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin>>t;while(t--){
        int n,d,k;cin>>n>>d>>k;vector<Z> v(k);
        for(int i=0;i<k;i++){cin>>v[i].l>>v[i].r;v[i].id=i;}
        if(!k){cout<<1<<" "<<1<<"\n";continue;}
        vector<Z> L=v,R=v;sort(L.begin(),L.end(),[](auto &a,auto &b){return a.l<b.l;});
        sort(R.begin(),R.end(),[](auto &a,auto &b){return a.r<b.r;});
        vector<bool> in(k,false);int c=0,p1=0,p2=0;long long mx=-1,mn=LLONG_MAX;int da=1,db=1;
        for(int x=1;x<=n-d+1;x++){
            while(p1<k&&L[p1].l<=x+d-1){if(!in[L[p1].id]){in[L[p1].id]=true;c++;}p1++;}
            while(p2<k&&R[p2].r<x){if(in[R[p2].id]){in[R[p2].id]=false;c--;}p2++;}
            long long y=c;
            if(y>mx){mx=y;da=x;}
            if(y<mn){mn=y;db=x;}
        }
        cout<<da<<" "<<db<<"\n";
    }
}




// #include <bits/stdc++.h>
// using namespace std;
// #define lli long long

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         lli n, d, k, l, r;
//         cin >> n >> d >> k;

//         vector<pair<int, int>> c(k);
//         for (int i = 0; i < k; i++) {
//             cin >> l >> r;
//             c[i] = make_pair(l - 1, r - 1);
//         }

//         // Compute Maximum Intersection Points
//         vector<pair<int, int>> events;
//         for (auto segment : c) {
//             events.push_back({segment.first, +1});
//             events.push_back({segment.second + 1, -1});
//         }

//         sort(events.begin(), events.end()); // Sort events by position

//         int active = 0, max_intersection = 0, max_index = -1;
//         for (size_t i = 0; i < events.size(); i++) {
//             active += events[i].second; // Increment or decrement active segments
//             if (active > max_intersection) {
//                 max_intersection = active;
//                 max_index = events[i].first; // Update index of max intersection
//             }
//         }

//         // Compute Minimum Intersection Points
//         sort(c.begin(), c.end(), [](pair<int, int> a, pair<int, int> b) {
//             return a.second < b.second; // Sort by end points
//         });

//         int min_points = 0;
//         int last_point = -1;
//         vector<int> min_indices;
//         for (auto segment : c) {
//             if (segment.first > last_point) {
//                 last_point = segment.second;
//                 min_points++;
//                 min_indices.push_back(last_point + 1); // Store index of chosen point
//             }
//         }
//         sort(min_indices.begin(), min_indices.end()),
//         cout << max_index + 1 << " " << min_indices[0] << endl;
        
//     }

//     return 0;
// }
