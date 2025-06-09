#include<bits/stdc++.h>
using namespace std;
#include <unordered_map>

int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<int,int>Map;
        int n,x;
        cin >>n;
        for(int i=0;i<n;i++){
            cin >>x;
            if (Map.find(x)!=Map.end()){
                Map[x]++;
            }else{
                Map[x]=1;
            }

        }
        int res=0;
        for(auto c : Map){
            res+=c.second/2;
        }
        cout <<res<<endl;
    }
    return 0;
}