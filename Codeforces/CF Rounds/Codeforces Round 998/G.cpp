#include <bits/stdc++.h>
using namespace std;

struct PairInfo {
    int m, M;
    int initFlip;
};


bool canSortWithParity(vector<PairInfo> &pairs, int desiredParity) {
    int n = (int) pairs.size();
    static bool dpPrev[2][2], dpCurr[2][2];

    for (int f=0; f<2; f++){
        for (int p=0; p<2; p++){
            dpPrev[f][p] = false;
        }
    }

    dpPrev[0][0] = true;
    dpPrev[1][1] = true;

    vector<int> top0(n+1), bot0(n+1), top1(n+1), bot1(n+1);
    for (int i=1; i<=n; i++){
        auto &P = pairs[i-1];
        top0[i] = P.m;
        bot0[i] = P.M;
        top1[i] = P.M;
        bot1[i] = P.m;
    }
    vector<int> topUsed0(n+1), botUsed0(n+1), topUsed1(n+1), botUsed1(n+1);
    for (int i=1; i<=n; i++){
        topUsed0[i] = pairs[i-1].m;
        botUsed0[i] = pairs[i-1].M;
        topUsed1[i] = pairs[i-1].M;
        botUsed1[i] = pairs[i-1].m;
    }

    int prevTop[2], prevBot[2];

    for(int i=2; i<=n; i++){

        for(int f=0; f<2; f++){
            for(int p=0; p<2; p++){
                dpCurr[f][p] = false;
            }
    }

        for(int fPrev=0; fPrev<2; fPrev++){
            for(int pPrev=0; pPrev<2; pPrev++){
                if(!dpPrev[fPrev][pPrev]) continue;

                int Tprev = topUsed0[i-1], Bprev = botUsed0[i-1];
                if(fPrev==1){
                    Tprev = topUsed1[i-1];
                    Bprev = botUsed1[i-1];
                }

                for(int f=0; f<2; f++){
                    int Tcurr = (f==0 ? topUsed0[i] : topUsed1[i]);
                    int Bcurr = (f==0 ? botUsed0[i] : botUsed1[i]);
                    if(Tcurr> Tprev && Bcurr> Bprev){
                        int pNew = (pPrev + f) % 2;
                        dpCurr[f][pNew] = true;
                    }
                
                }
             }
        }

        for(int f=0; f<2; f++){
            for(int p=0; p<2; p++){
                dpPrev[f][p] = dpCurr[f][p];
            }
        }
    }


    if(dpPrev[0][desiredParity] || dpPrev[1][desiredParity]){
        return true;
    } else {
        return false;
    }
}

bool solveOneTest() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n; i++){
        cin >> B[i];
    }

    vector<PairInfo> P(n);
    int initParity = 0;
    for(int i=0; i<n; i++){
        int mi = min(A[i], B[i]);
        int Ma = max(A[i], B[i]);
        P[i].m = mi;
        P[i].M = Ma;


        int iflip = 0;
        if(A[i] == Ma) iflip=1;
        P[i].initFlip = iflip;
        initParity ^= iflip;
    }
    sort(P.begin(), P.end(), [&](auto &L, auto &R){
        if(L.m != R.m) return L.m < R.m;
        return L.M < R.M;
    });
    if(canSortWithParity(P, initParity)) {
        return true;
    }


    sort(P.begin(), P.end(), [&](auto &L, auto &R){
        if(L.M != R.M) return L.M < R.M;
        return L.m < R.m;
    });
    if(canSortWithParity(P, initParity)) {
        return true;
    }

    return false;
}

int main(){

    int t;cin >> t;
    while(t--){
        if(solveOneTest()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}