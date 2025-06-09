#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;

long long modexp(long long base, long long exp){

    long long r=1%MOD;  base%=MOD;
    while(exp>0 ){
        if(exp&1)r=( r*base)%MOD;
        base=(base *base)%MOD;  exp>>=1;
    }
    return r;
}

const int MAXK =100000;
const int MAXA = 16;

vector< long long> polyA[MAXA+1];  

vector<long long > buildBasePoly(int a){

    vector<long long> val(a+1,0LL);
    if(a==0){

        for(int L=1;L<=0;L++){ }

        return {1}; 
    }

    val[0]=0; 
    
    
    auto comb =  [&](int x, int y){
        
        
        if(y<0||y> x)  return 0LL;
        long long res=1; 
        for(int i=0;i<y;i++){
            res = res*(x-i)%MOD; 
            long long inv=(i+1); 
     
     
            inv=modexp(inv,MOD-2);
            res=(res*inv)%MOD;
        }
        return  res;
    };
    for(int L=1;L<=a;L++){
        val[L ]= comb(a+L-1, L-1);
    }


    
    vector<vector<long long>> f(a+1, vector<long long>(a+1,0));
    for(int i=0;i<=a;i++) f[i][0]=val[i];
    for(int j=1;j<=a; j++){
        for(int i=0;i<=a-j;i++){
            long long num=(f[i+1][j-1] - f[i][j-1])%MOD; 
            if(num<0) num+=MOD;
            long long den=( long long) (j); 
            
            long long invDen=modexp(den, MOD-2);
            f[i][j]=(num*invDen)% MOD;
        }
    }
    
    
    vector<long long> coef( a+1,0LL);
    
   
   
    vector<long long> polyPj; 
    
    polyPj.push_back(1 ); 
    
    for(int j=0;j<=a;j++){
        
        
        for(int d=0; d<(int)polyPj.size(); d++){
            long long tmp = (polyPj[d]*f[0][j])%MOD;
            coef[d] = (coef[d] + tmp)%MOD;
        }

        if(j==a) break; 

        int sz=(int)polyPj.size();
        vector<long long> newP(sz+1,0LL);
        for(int d=0; d<sz; d++){

            long long c= polyPj[d];
          
          
            newP[d+1 ]=( newP[d+1]+c)%MOD;

            long long neg=( (long long)(MOD - j%MOD)* c )%MOD;
            newP[d]=(newP[d]+ neg)%MOD;
        }
        polyPj.swap( newP);
    }
    
    
    
    return coef;
}

vector<long long> polyMul(vector<long long> &A, vector<long long> &B){
    int da=(int)A.size()-1;
    int db=(int)B.size()-1;
    int dc=da+db; 
    vector<long long> C( dc+1,0LL);
    for(int i=0;i <=da; i++){
        long long  ai=A[i ];
        if(ai==0)continue;
        for(int j=0;j<=db ;j++){
            long long  tmp=(ai*B[j])%MOD;
            C[i+j]=(C[i+j ]+tmp) %MOD;
        }
    }
    return C;
}


int  MAXNCOEF=17; 
vector<long long > polyOfOne={1}; 

int spf[MAXK+1]; 

int main(){
   

    {
        for( int i=2;i<=MAXK;i++)spf[i]=0;
        for(int i=2;i<=MAXK;i++){
            if(spf[i] == 0){
                spf[i]=i;
                if((long  long)i*(long long)i>MAXK)continue;
                for(int j=i*i;j <=MAXK; j+=i){
                    if(spf[j]==0) spf[ j]=i;
                }
            }
        }
        spf[1]=1; 
    }


    for(int a=0;a<=MAXA;a++){
        polyA[a] = buildBasePoly(a);
    }


    vector<long long> polyX[MAXK+1], sumX[MAXK+1];

  
    auto factor = [&](int x){

        vector<pair<int,int>> res;
        while(x>1){
            int p=spf[x]; 
            int c=0;
            while(spf[x]==p){x/=p; c++;}
            res.push_back({p,c});
        }
        return res;
    };
 
    vector<long long> sumPowPoly[17]; 
    {

        for(int m=0;m<=16;m++){
            int deg=m+1;
            vector<long long> val(deg+1,0LL); 
            


            long long curr=0;
            for(int i=0;i<=deg;i++){
                if(i==0) {val[i]=0;continue;}

                long long p=1;
                for(int tmp=0;tmp<m;tmp++){
                    p=(p*i)%MOD;
                }
                curr=(curr + p)%MOD;
                val[i]=curr;
            }
            
            vector<vector<long long>> f(deg+1, vector<long long>(deg+1,0));
            for(int i=0;i<=deg;i++){
                f[i][0]=val[i];
            }
            for(int j=1;j<=deg;j++){
                for(int i=0;i<=deg-j;i++){
                    long long num=(f[i+1][j-1]-f[i][j-1])%MOD; 
                    if( num<0) num+=MOD;
                    long long den=j; 
                    
                    long long invDen= modexp(den,MOD-2);
                    f[i][j ]=(num*invDen)%MOD;
                }
            }

            vector<long long> coef(deg+1,0LL);
            vector<long long>  polyPj(1,1LL); 
            for(int j=0;j<=deg;j++){

                long long c=f[0][j];
                for(int d=0; d<(int)polyPj.size(); d++){
                    long long tmp=(polyPj[d]*c)%MOD;
                    coef[d]=(coef[d]+tmp)%MOD;
                }
                if(j==deg) break;


                int psz=(int)polyPj.size();
                vector<long long> newP(psz+1,0LL);
                for(int d=0; d<psz; d++){

                    long long cc= polyPj[d];

                    newP[d+1]=(newP[d+1]+cc)%MOD;
                    long long neg=( (MOD - j%MOD)* cc )%MOD;
                    newP[d]=(newP[d]+neg)%MOD;
                }
                polyPj.swap(newP);
            }
            sumPowPoly[m]= coef; 
        }
    }

    auto buildPartialSumPoly = [&](vector<long long> &p)->vector<long long>{
        
        int D=(int)p.size()-1;
        vector<long long> S(D+2,0LL);
        for(int d=0;d<=D;d++){
            long long cd=p[d]%MOD;
            if(cd==0)continue;
            auto &sp = sumPowPoly[d]; 
            for(int i=0;i<(int)sp.size();i++){
                long long tmp=(cd*sp[i])%MOD;
                S[i]=(S[i]+tmp)%MOD;
            }
        }


        while(S.size()>1 && S.back()==0) S.pop_back();
        return S;
    };

    
    auto polyEval = [&](vector<long long> &coef, vector<long long> &xpows){
        long long ans=0;

        for(int i=0; i<(int)coef.size(); i++){
            if(coef[i]!=0){
                long long tmp=(coef[i]* xpows[i])%MOD;
                ans=(ans+tmp)%MOD;
            }
        }
        return ans;
    };

    {
        
        for(int x=1;x<=MAXK;x++){
            
            if( x==1){
                polyX[x]= polyOfOne; 
                sumX[x]= buildPartialSumPoly(polyX[x]); 
                continue;
            }
            vector<pair<int,int>> fs = factor(x);

            vector<long long> pol= polyOfOne; 
            for(auto &pp: fs){ 

                int e=pp.second;
                pol = polyMul(pol, polyA[e]);
            }
            polyX[x]= pol;

            sumX[x]= buildPartialSumPoly(pol);
        }
    }

    int T;cin>>T;
    while(T--){
        long long K,N;cin>>K>>N;
        
        vector<long long> pw(18,1LL);
        {
            long long cur=1;
            for(int i=1;i<=17;i++){
                cur=(cur*N)%MOD;
                pw[i]=cur;
            }
        }

        
        int BUF_SZ = 200000; 

        for(int x=1;x<=K;x++){
            long  long ans= polyEval(sumX[x], pw);
            cout<<ans <<( (x==K)? '\n':' ' );
        }
    }
    return 0;
}
