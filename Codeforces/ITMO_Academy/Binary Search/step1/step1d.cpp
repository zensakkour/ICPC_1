#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, k;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> q(n);

    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    cin >> k;
    int i=0, q1, q2;
    int lw = -1, hi = n, mid;

    while(i < k){
        cin >> q1 >> q2;

        lw = -1, hi = n, mid;
        while(lw + 1 < hi){ // arr[lw] < q   && arr[hi] >= q
            mid= lw + (hi - lw)/2;
            if(arr[mid] >= q1){
                hi = mid;
            }else lw = mid;
        }
        
        int l = hi + 1;
        
        lw = -1, hi = n, mid;
        while(lw + 1 < hi){ // arr[lw] <= q && arr[hi] > q
            mid= lw + (hi - lw)/2;
            if(arr[mid] <= q2){
                lw = mid;
            }else hi = mid;
        }
        int r = lw + 1;

        cout <<r-l+1<<" ";
        i++;
    }

    return 0;
}