#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(n+m);
    
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    for(int i = 0;i < m;i++){
        cin >> b[i];
    }
    
    int i = 0, j = 0;
    while(i < n || j < m){
        if(i == n || (j < m && a[i] > b[j]) ){
            c[i + j] = b[j];
            j++;
        }else {
            c[i + j] = a[i];
            i++;
        }
    }
    for(int i = 0;i< n + m;i++){
        cout <<c[i]<<' ';
    }

    return 0;
}