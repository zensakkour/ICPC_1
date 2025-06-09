#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,k;
    cin >>n>>k;
    vector<long long> arr(n);
    vector<long long>q(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<k;i++){
        cin>>q[i];
    }
    int i=0;
    while(i<k){
        int lw=0,hi=n-1,mid=lw+(hi-lw)/2;
        while(lw<=hi){
            mid=lw+(hi-lw)/2;
            if(arr[mid]==q[i]){
                cout<<"YES"<<endl;
                goto nxt;
            }else if(arr[mid]<q[i]){
                lw=mid+1;
            }else hi=mid-1;
        }
        cout<<"NO"<<endl;
        nxt:
        i++;
    
    }
    return 0;
}