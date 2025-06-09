#include<bits/stdc++.h>
using namespace std;

int check_count(string s){
    int cmp=0;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])cmp++;
    }
    return cmp;
}

int main(){
    int t;
    cin>>t;
    string a,b,s;
    int n,m;
    while(t--){
        s="";
        
        cin >>n>>m;
        cin >>a>>b;
        reverse(b.begin(),b.end());
        s=a+b;
        if(check_count(s)<=1)cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}