#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> similar(3000, vector<int>(3000,-1));

bool areSimilar(const vector<int>& a, const vector<int>& b,int i,int j) {

    if(similar[i][j]!=-1)return similar[i][j];
    int diffCount = 0;
    int first = -1, second = -1;

    for (int z = 0; z < a.size(); z++) {
        if (a[z] != b[z]) {
            diffCount++;
            if (diffCount == 1) first = z;
            if (diffCount == 2) second = z;
            if (diffCount > 2) {
                similar[i][j]=false;
                similar[j][i]=false;
                return false;}
        }
    }

    if (diffCount == 2) {
        similar[i][j]= (a[first] == b[second] && a[second] == b[first]);
        similar[j][i]= similar[i][j];
        return (a[first] == b[second] && a[second] == b[first]);
    }
    similar[i][j]=true;
    similar[j][i]=true;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> computers(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> computers[i][j];
        }
    }
    int res=0;

    for(int v=0;v<n;v++){
        vector<int> indep_set;
        indep_set.push_back(v);  
        for (int i = 0; i < n; i++) {
            bool can_add = true;
            for (int j : indep_set) {
                
                if ((j==i) || areSimilar(computers[i],computers[j],i,j)) {
                    can_add = false;
                    break;
                }
            }
            if (can_add) {
                indep_set.push_back(i);
                // for (auto z : computers[i]){cout <<z<<" ";}
                // cout <<"zen "<<endl;
            }
        }

        // cout <<"#####"<<endl;
        // for(auto i : indep_set){
        //     for (auto j : computers[i]){cout <<j<<" ";}
        //     cout <<endl;
        // } 
        res=max(res,int(indep_set.size()));
    }
    cout <<res<< endl;
    return 0;
}