#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("O4")
#pragma GCC optimize("O5")
#pragma GCC optimize("O6")
#pragma GCC optimize("O7")
#include<bits/stdc++.h>
using namespace std;

// void print(vector<pair<int,int>> vec){
//     for(auto v :vec){
//         cout<<v.first<<" "<<v.second<<endl;
//     }
// }
// void printG(vector<vector<int>> vec){
//     for(int i=1;i<6;i++){
//         for(int j=1;j<6;j++){
//             cout<<vec[i][j]<<" ";
//         }
//         cout <<endl;
//     }

// }
bool valide(int vec[7][7], bool c){
    for (int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            if(vec[i][j]==1 && (i+j)%2==c){
                if(vec[i-1][j-1]==1 && vec[i+1][j+1]==1 && vec[i-1][j+1]==1 && vec[i+1][j-1]==1){
                    return false;
                }
            }
        }
    }
    return true;
}

bool chk(int flips, int vec[][7], vector<pair<int,int>>& RC, int idx , bool c){
    // print(RC);
    if (flips==0){
        // cout<<"v="<<valide(vec)<<endl;
        // if (valide(vec)==true){
        //     cout<<"("<<RC[idx].first<<" "<<RC[idx].second<<")"<<endl;
        // }
        return valide(vec,c);
    }
    if (idx==RC.size()){
        return false;
    }

    bool res=false;
    res |= chk(flips,vec,RC,idx+1,c);
    vec[RC[idx].first][RC[idx].second] ^= 1;
    res |= chk(flips-1,vec,RC,idx+1,c);
    vec[RC[idx].first][RC[idx].second] ^= 1 ;
    return res;

}




int main(){
    int t;
    cin>>t;
    char a;
    int arr[7][7];
    vector<pair<int,int>> E,O;
     for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                if((i+j)%2==0){
                    E.push_back(make_pair(i,j));
                }else{O.push_back(make_pair(i,j));}
                
                
            }
        } 
    while (t--){
        
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                cin>>a;
                arr[i][j]=(a=='B');
                  
            }
        } 
        int res=0;
        for(int i=0;i<=7;i++){
            if(chk(i,arr,E,0,0)==true){
                res+=i;
                break;
            }
        }
        for(int i=0;i<=7;i++){
            if(chk(i,arr,O,0,1)==true){
                res+=i;
                break;
            }
        }
        cout<<res<<endl;

    }
    return 0;
}