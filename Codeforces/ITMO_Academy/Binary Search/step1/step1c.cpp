#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    vector<long long> q(n);

    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<k;i++) cin >> q[i];

    int i=0;
    while(i < k){
        int lw = -1, hi = n, mid;

        while(lw + 1 < hi){ // arr[lw] < q   && arr[hi] >= q
            mid= lw + (hi - lw)/2;
            if(arr[mid] >= q[i]){
                hi = mid;
            }else lw = mid;
        }
        i++;
        cout<<hi+1<<endl;
    
    }

    /*5 5
    3 3 5 8 9
    2 4 8 1 10*/
    return 0;
}