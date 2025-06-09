#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1.0L);
long double EPS = 1e-18;


long double clampVal(long double v){
    if(v>1.0L) v=1.0L;
    if(v<-1.0L) v=-1.0L;
    return v;
}

long double normalizeAngle(long double ang){
    ang = fmodl(ang, 2.0L*PI);
    if(ang<0) ang += 2.0L*PI;
    return ang;
}

long double angleDiff(long double a,long double b){
  long double d = fabsl(a - b);
    if(d > PI) d = 2.0L*PI - d;
    return d;
}

long double transitionCost( vector<long double> &A,  vector<long double> &B){
  long double m=0.0L;
    for(size_t i=0; i<A.size(); i++){
      long double d = angleDiff(A[i], B[i]);
        m = max(m, d);
    }
    return m;
}

 pair<long double,long double> forward3( vector<long double> &theta,  vector<long double> &L){
  long double t1=theta[0], t2=theta[1], t3=theta[2];
  long double x = L[0]*cosl(t1) + L[1]*cosl(t1 + t2) + L[2]*cosl(t1 + t2 + t3);
  long double y = L[0]*sinl(t1) + L[1]*sinl(t1 + t2) + L[2]*sinl(t1 + t2 + t3);
    return {x,y};
}

 array<array<long double,3>,2> jac3( vector<long double> &theta,  vector<long double> &L){
  long double t1 = theta[0], t2 = theta[1], t3 = theta[2];
  long double s12 = sinl(t1 + t2), c12 = cosl(t1 + t2);
  long double s123 = sinl(t1 + t2 + t3), c123 = cosl(t1 + t2 + t3);
  long double dx_dt1 = -L[0]*sinl(t1) - L[1]*s12 - L[2]*s123;
  long double dx_dt2 = -L[1]*s12 - L[2]*s123;
  long double dx_dt3 = -L[2]*s123;
  long double dy_dt1 =  L[0]*cosl(t1) + L[1]*c12 + L[2]*c123;
  long double dy_dt2 =  L[1]*c12 + L[2]*c123;
  long double dy_dt3 =  L[2]*c123;
    array<array<long double,3>,2> J;
    J[0] = {dx_dt1, dx_dt2, dx_dt3};
    J[1] = {dy_dt1, dy_dt2, dy_dt3};
    return J;
}

 vector<long double> solve2x3( array<array<long double,3>,2> &J,long double dx,long double dy){
    array<long double,9> M; 
    array<long double,3> R;
    M[0] = J[0][0]*J[0][0] + J[1][0]*J[1][0];
    M[1] = J[0][0]*J[0][1] + J[1][0]*J[1][1];
    M[2] = J[0][0]*J[0][2] + J[1][0]*J[1][2];
    M[3] = J[0][1]*J[0][0] + J[1][1]*J[1][0];
    M[4] = J[0][1]*J[0][1] + J[1][1]*J[1][1];
    M[5] = J[0][1]*J[0][2] + J[1][1]*J[1][2];
    M[6] = J[0][2]*J[0][0] + J[1][2]*J[1][0];
    M[7] = J[0][2]*J[0][1] + J[1][2]*J[1][1];
    M[8] = J[0][2]*J[0][2] + J[1][2]*J[1][2];
    R[0] = -(J[0][0]*dx + J[1][0]*dy);
    R[1] = -(J[0][1]*dx + J[1][1]*dy);
    R[2] = -(J[0][2]*dx + J[1][2]*dy);
    vector<long double> dtheta(3, 0.0L);
  long double a[3][3];
    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            a[r][c] = M[r*3 + c];
        }
    }
  long double b[3];
    for(int i=0; i<3; i++){
        b[i] = R[i];
    }
    for(int i=0; i<3; i++){
        int pivot=i;
      long double val = fabsl(a[i][i]);
        for(int r=i+1; r<3; r++){
          long double tmp = fabsl(a[r][i]);
            if(tmp > val){
                pivot = r; val = tmp;
            }
        }

        if(pivot != i){
            for(int c=0; c<3; c++){
                std::swap(a[i][c], a[pivot][c]);
            }
            std::swap(b[i], b[pivot]);
        }

        if(fabsl(a[i][i]) < 1e-28L){
            return {0.0L, 0.0L, 0.0L};
        }

      long double diag = a[i][i];
        for(int c=0; c<3; c++){
            a[i][c] /= diag;
        }

        b[i] /= diag;
        for(int rr=0; rr<3; rr++){
            if(rr == i) continue;
          long double f = a[rr][i];
            for(int cc=0; cc<3; cc++){
                a[rr][cc] -= f*a[i][cc];
            }
            b[rr] -= f*b[i];
        }
    }
    for(int i=0; i<3; i++){
        dtheta[i] = b[i];
    }

    return dtheta;
}

vector<long double> newtonRefine3(long double x,long double y, vector<long double> &L,vector<long double> init){
    vector<long double> th = init;
     int MAX_ITER = 2000; 
    for(int iter=0; iter<MAX_ITER; iter++){
        auto [xx,yy] = forward3(th,L);
      long double dx = xx - x;
      long double dy = yy - y;
      long double err = sqrtl(dx*dx + dy*dy);
        if(err < 1e-15L){
            break; 
        }
        auto J = jac3(th,L);
        auto step = solve2x3(J, dx, dy);
      long double stepSize = sqrtl(step[0]*step[0] + step[1]*step[1] + step[2]*step[2]);
        if(stepSize > 0.4L){
          long double fac = 0.4L / stepSize;
            step[0] *= fac;
            step[1] *= fac;
            step[2] *= fac;
        }
        for(int i=0; i<3; i++){
            th[i] = normalizeAngle(th[i] + step[i]);
        }
    }
    return th;
}

vector<vector<long double>> ik2(long double x,long double y,long double l1,long double l2){
  long double d = hypotl(x, y);
  long double c2 = clampVal((d*d - l1*l1 - l2*l2)/(2.0L*l1*l2));
  long double th2_1 = acosl(c2);
  long double th2_2 = 2.0L*PI - th2_1;
    vector<vector<long double>> sols;
    for(long double th2: {th2_1, th2_2}){
      long double num = l2*sinl(th2);
      long double den = l1 + l2*cosl(th2);
      long double th1 = atan2l(y, x) - atan2l(num, den);
        th1 = normalizeAngle(th1);
        th2 = normalizeAngle(th2);
        sols.push_back({th1, th2});
    }
    return sols;
}


vector<vector<long double>> ik3_fine(long double x,long double y,long double l1,long double l2,long double l3){
    vector<long double> L = {l1, l2, l3};
    vector<vector<long double>> sols;
  long double delta = 0.005L;
    for(long double a = -PI; a < PI; a += delta){
      long double c = cosl(a), s = sinl(a);
      long double L_eff = sqrtl(l2*l2 + l3*l3 + 2.0L*l2*l3*c);
        if(fabsl(L_eff) < 1e-20L) continue;
      long double beta = atan2l(l3*s, (l2 + l3*c));
        auto c2 = ik2(x,y,l1,L_eff);
        for(auto &cc: c2){
          long double t1 = cc[0];
          long double t2p = cc[1];
          long double t2 = t2p - beta;
          long double t3 = a;
            t1 = normalizeAngle(t1);
            t2 = normalizeAngle(t2);
            t3 = normalizeAngle(t3);
            vector<long double> guess = {t1, t2, t3};
            auto refined = newtonRefine3(x, y, L, guess);
            auto [xx,yy] = forward3(refined, L);
          long double err = hypotl(xx - x, yy - y);
            if(err < 1e-14L){
                sols.push_back(refined);
            }
        }
    }
    return sols;
}

vector<vector<long double>> ik3_basic(long double x,long double y,long double l1,long double l2,long double l3){
    vector<vector<long double>> sols;
  long double l_eff = l2 + l3;
  long double d = hypotl(x,y);
  long double c2 = clampVal((d*d - l1*l1 - l_eff*l_eff)/(2.0L*l1*l_eff));
  long double th2_1 = acosl(c2);
  long double th2_2 = 2.0L*PI - th2_1;
    vector<long double> L={l1,l2,l3};
    for(long double th2 : {th2_1, th2_2}){
      long double num = l_eff*sinl(th2);
      long double den = l1 + l_eff*cosl(th2);
      long double th1 = atan2l(y, x) - atan2l(num, den);
        th1 = normalizeAngle(th1);
        th2 = normalizeAngle(th2);
      long double th3 = 0.0L;
        vector<long double> guess = {th1, th2, th3};
        auto refined = newtonRefine3(x,y,L, guess);
        auto [xx,yy] = forward3(refined,L);
      long double err = hypotl(xx - x, yy - y);
        if(err<1e-14L){
            sols.push_back(refined);
        }
    }
    return sols;
}


vector<vector<long double>> ik3(long double x,long double y,long double l1,long double l2,long double l3){
    auto sols = ik3_fine(x, y, l1, l2, l3);
    if(sols.empty()){
        sols = ik3_basic(x, y, l1, l2, l3);
    }
    return sols;
}


int main(){

    int k;cin >> k;
    vector<long double> L(k);
    for(int i=0; i<k; i++){
      long double temp; cin >> temp;
        L[i] = temp;
    }

    int n; cin >> n;
    vector<pair<long double,long double>> strawberries(n);
    for(int i=0; i<n; i++){
      long double xx,yy; cin >> xx >> yy;
        strawberries[i] = {xx,yy};
    }

    vector<vector<vector<long double>>> solutions(n);

    if(k==2){
        for(int i=0; i<n; i++){
          long double x = strawberries[i].first;
          long double y = strawberries[i].second;
            solutions[i] = ik2(x, y, L[0], L[1]);
        }
    } else {
        for(int i=0; i<n; i++){
          long double x = strawberries[i].first;
          long double y = strawberries[i].second;
            solutions[i] = ik3(x, y, L[0], L[1], L[2]);
        }
    }
    vector<long double> currentConfig(k,0.0L);
    vector<bool> used(n,false);
    vector<int> order; 
    order.reserve(n);

    vector<vector<long double>> chosenConfig(n);
    for(int step=0; step<n; step++){
        int bestIdx = -1;
      long double bestCst = 1e30L;
        vector<long double> bestAngles;
        for(int i=0; i<n; i++){
            if(used[i]) continue;
          long double localCst = 1e30L;
            vector<long double> localConf;

            for(auto &cand : solutions[i]){
              long double cst = transitionCost(currentConfig, cand);
                if(cst < localCst){
                    localCst = cst;
                    localConf = cand;
                }
            }

            if(localCst < bestCst){
                bestCst=localCst;
                bestIdx=i;
                bestAngles=localConf;
            }
        }
        used[bestIdx] = true;
        order.push_back(bestIdx);
        chosenConfig[bestIdx] = bestAngles;
        currentConfig = bestAngles;
    }

    cout << fixed << setprecision(20);

    for(auto idx : order){
        cout << (idx+1);
        for(auto &ang : chosenConfig[idx]){
            double outVal = (double)ang; 
            cout << " " << outVal;
        }
        cout << "\n";
    }
    return 0;
}