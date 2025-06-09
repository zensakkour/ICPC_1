#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        cin >> b[i];
    }
    int i, j;
    for(int j = 0;j < m;j++){
        while((i < n) && (b[j] > a[i])){
            i++;
        }
        // if(i != n)i--;
        cout << i <<' ';
    }

    return 0;
}