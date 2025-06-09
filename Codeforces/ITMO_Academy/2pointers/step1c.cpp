#include<bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
    lli n, m;cin >> n >> m;
    vector<lli> a(n), b(m);

    for(lli i = 0;i < n;i++){
        cin >> a[i];
    }
    for(lli i = 0;i < m;i++){
        cin >>b[i];
    }
    lli i = 0, j = 0, res = 0;
    while((i < n) && (j < m)){
        if(i < n && a[i] < b[j]){
            i++;
        }else if(j < m && a[i] > b[j]){
            j++;
        }else {
            lli tmp = a[i], ii = 0, jj = 0;
            while(i < n && a[i] == tmp){
                ii++;i++;
            }
            while(j < m && b[j] == tmp){
                jj++;j++;
            }
            res += ii * jj;
        }
        
    }
    cout << res << endl;
    return 0;
}