#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e10;

long long n;
vector<vector<long long>> capacity;
vector<vector<long long>> adj;
long long ptr[10000];

long long bfs(long long s, long long t, vector<long long>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<long long, long long>> q;
    q.push({s, INF});

    while (!q.empty()) {
        long long cur = q.front().first;
        long long flow = q.front().second;
        q.pop();

        for (long long next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                long long new_flow = min(flow, capacity[cur][next]);
                if (next == t){
                    // cout <<cur<<" "<<next<<" "<<new_flow<<endl;
                    return new_flow;}
                q.push({next, new_flow});
            }
            
            
        }
    }

    return 0;
}

long long maxflow(long long s, long long t) {
    long long flow = 0;
    vector<long long> parent(n);
    long long new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        // cout <<new_flow<<endl;

        long long cur = t;
        while (cur != s) {
            long long prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


int main(){
    int nn,m,sum=0;
    cin >>nn>>m;
    int source=0;
    int sink=1+nn+m;
    n=2+nn+m;
    capacity.assign(n, vector<long long>(n, 0));
    adj.assign(n, vector<long long>());

    
    vector<vector<int>> arr(nn,vector<int>(m,0));
  

    for(int i=0;i<nn;i++){
        for(int j=0;j<m;j++){
            cin >>arr[i][j];
            sum+=arr[i][j];
            // cout <<i<<endl;
            if (arr[i][j]==0){
                adj[i+1].push_back(j+nn+1);
                adj[j+nn+1].push_back(i+1);
                capacity[i+1][j+nn+1] = 1; 
                capacity[j+nn+1][i+1] = 0;
            }
            else{
                adj[i+1].push_back(j+nn+1);
                adj[j+nn+1].push_back(i+1);
                capacity[i+1][j+nn+1] = 0; 
                capacity[j+nn+1][i+1] = 1;
            }
        }
    }
  
    int sumA=0;
    vector<int> A(nn,0);
    vector<int> B(nn,0);
    for(int i=0;i<nn;i++){
        cin >>A[i];
        sumA+=A[i];
        adj[source].push_back(i+1);
        adj[i+1].push_back(source);
        capacity[source][i+1] = A[i]; 
        capacity[i+1][source] = 0;
    }
    
    int sumB=0;
    for(int i=0;i<m;i++){
        cin >>B[i];
        sumB+=B[i];

        adj[sink].push_back(i+nn+1);
        adj[i+nn+1].push_back(sink);
        capacity[i+nn+1][sink] = B[i];
        capacity[sink][i+nn+1] = 0; 
    }
    int mf=maxflow(source,sink);
    if(mf!=sumA || mf!=sumB){
       cout<<"-1"<<endl;
    }else { cout <<mf;}
}





















// struct Teammate {
//     string name;
//     int onCallTime;
// };

// int main() {
//     map<string, int> schedule1, schedule2;

//     string line;
//     while (getline(cin, line) && line != "======") {
//         istringstream iss(line);
//         string name;
//         int start, end;
//         iss >> start >> end >> name;

//         for (int i = start; i < end; ++i) {
//             schedule1[name]++;
//         }
//     }

//     while (getline(cin, line)) {
//         istringstream iss(line);
//         string name;
//         int start, end;
//         iss >> start >> end >> name;

//         for (int i = start; i < end; ++i) {
//             schedule2[name]++;
//         }
//     }

//     // Compare schedules and output differences
//     vector<Teammate> differences;
//     for (const auto& entry : schedule1) {
//         string name = entry.first;
//         int onCallTime1 = entry.second;
//         int onCallTime2 = schedule2[name];

//         if (onCallTime1 != onCallTime2) {
//             Teammate diffTeammate;
//             diffTeammate.name = name;
//             diffTeammate.onCallTime = onCallTime2 - onCallTime1;
//             differences.push_back(diffTeammate);
//         }
//     }

//     // Sort the differences alphabetically
//     sort(differences.begin(), differences.end(), [](const Teammate& a, const Teammate& b) {
//         return a.name < b.name;
//     });

//     // Output the differences
//     if (differences.empty()) {
//         cout << "No differences found." << endl;
//     } else {
//         for (const auto& diff : differences) {
//             cout << diff.name<< " " << (diff.onCallTime > 0 ? "+" : "-") << abs(diff.onCallTime) << endl;
//         }
//     }

//     return 0;
// }