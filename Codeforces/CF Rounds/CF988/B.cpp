#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        vector<int> v,freq(k+1,0);
        for(int i=0;i<k;i++){
            int x;cin >>x;
            v.push_back(x);
            freq[x]++;
        }
        for(int i=1;i<=k;i++){
            if (i*i+2==k){
                if (freq[i]>1){cout <<i<<" "<<i<<endl;break;}
            }else if ((k-2)%i==0){
                if (freq[i]>0 && freq[(k-2)/i]>0) {cout <<i<<" "<<(k-2)/i<<endl;break;}
            }
        }
    }

    return 0;
}