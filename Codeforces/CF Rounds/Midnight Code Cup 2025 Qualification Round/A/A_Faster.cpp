#include <bits/stdc++.h>
using namespace std;

static const double PI = acos(-1.0);

double clampVal(double v) {
    if(v > 1.0) v =1.0;
    if(v < -1.0)v = -1.0;
    return v;
}
 
double normalizeAngle(double ang) {
    ang = fmod(ang, 2.0*PI);
    if (ang < 0) ang += 2.0  *PI;
    return ang;

}
 
double angleDiff(double a, double b) {
    double diff = fabs(a - b);
    if(diff> PI) diff = 2.0*PI - diff;
    return diff;
}
 
double transitionCost(const vector<double> &A, const vector<double> &B) {
    double m = 0.0 ;
    
    for(int i = 0; i < (int)A.size(); i++) {
        double d = angleDiff(A[i], B[i]);
        if(d > m) m = d;
    }
    return m;
}
 
vector<vector<double>> ik2(double x, double y, double l1, double l2) {
    double d = hypot(x,y);
    double cos_th2 = clampVal((d*d - l1*l1 - l2*l2)/(2*l1*l2));
    double th2_1 = acos(cos_th2);
    double th2_2 = 2*PI - th2_1;
    vector<vector<double>> sols;
    for(double th2 : {th2_1, th2_2}) {
        double num = l2*sin(th2);
        double den = l1 + l2*cos(th2);
        double th1 = atan2(y, x) - atan2(num, den);
        th1 = normalizeAngle(th1);
        double t2 = normalizeAngle(th2);
        sols.push_back({th1, t2});
    }
    return sols;
}
 
vector<vector<double>> ik3_analytic(double x, double y, double l1, double l2, double l3) {
    vector<vector<double>> sols;
    double delta = 0.05; 
    for(double a = -PI; a < PI; a += delta) {
        double L_eff = sqrt(l2*l2 + l3*l3 + 2*l2*l3*cos(a));
        double beta = atan2(l3*sin(a), l2 + l3*cos(a));
        vector<vector<double>> cand = ik2(x, y, l1, L_eff);
        for(auto &sol : cand) {
            double theta1 = sol[0];
            double theta_prime = sol[1]; 
            double theta2 = theta_prime - beta;
            double theta3 = a;
            theta1 = normalizeAngle(theta1);
            theta2 = normalizeAngle(theta2);
            theta3 = normalizeAngle(theta3);
            double x_end = l1*cos(theta1) + l2*cos(theta1+theta2) + l3*cos(theta1+theta2+theta3);
            double y_end = l1*sin(theta1) + l2*sin(theta1+theta2) + l3*sin(theta1+theta2+theta3);
            double err = hypot(x_end - x, y_end - y);
            if(err < 1e-6) {
                sols.push_back({theta1, theta2, theta3});
            }
        }
    }
    return sols;
}
 
vector<vector<double>> ik3_basic(double x, double y, double l1, double l2, double l3) {
    double l_eff = l2 + l3;
    double d = hypot(x, y);
    double cos_th2 = clampVal((d*d - l1*l1 - l_eff*l_eff)/(2*l1*l_eff));
    double th2_1 = acos(cos_th2);
    double th2_2 = 2*PI - th2_1;
    vector<vector<double>> sols;
    for(double th2 : {th2_1, th2_2}) {
        double num = l_eff*sin(th2);
        double den = l1 + l_eff*cos(th2);
        double th1 = atan2(y, x) - atan2(num,den);
        th1 = normalizeAngle(th1);
        double t2 = normalizeAngle(th2);
        double t3 = 0.0;
        sols.push_back({th1, t2, t3});
    }
    return sols;
}
 

vector<vector<double>> ik3(double x, double y, double l1, double l2, double l3) {
    vector<vector<double>> sols = ik3_analytic(x, y, l1, l2, l3);
    if(sols.empty()){
        sols = ik3_basic(x, y, l1, l2, l3);
    }
    return sols;
}
 

int main(){
 
    int k;cin >> k;
    vector<double> L(k);
    for(int i = 0; i < k; i++) {
        cin >> L[i];
    }
 
    int n;
    cin >> n;
    vector<pair<double,double>> strawberries(n);
    for(int i = 0; i < n; i++){
        cin >> strawberries[i].first >> strawberries[i].second;
    }

    vector<vector<vector<double>>> solutions(n);
    for(int i = 0; i < n; i++){
        double x = strawberries[i].first;
        double y = strawberries[i].second;
        if(k == 2) {
            solutions[i] = ik2(x, y, L[0], L[1]);
        } else {
            solutions[i] = ik3(x, y, L[0], L[1], L[2]);
        }
    }
 
    
    vector<double> currentConfig(k, 0.0);
    vector<bool> painted(n, false);
    vector<int> order; 
    vector<vector<double>> chosenConfig(n);
 
    for(int step = 0; step < n; step++){
        int bestIdx = -1;
        double bestCost = 1e15;
        vector<double> bestConf;
 
        for(int s = 0; s < n; s++){
            if(painted[s]) continue;
            double localBest = 1e15;
            vector<double> localConf;
            for(auto &cand : solutions[s]){
                double cst = transitionCost(currentConfig, cand);
                if(cst < localBest){
                    localBest = cst;
                    localConf = cand;
                }
            }
            if(localBest < bestCost){
                bestCost = localBest;
                bestIdx = s;
                bestConf = localConf;
            }
        }
 
        painted[bestIdx] = true;
        order.push_back(bestIdx);
        chosenConfig[bestIdx] = bestConf;
        currentConfig = bestConf;
    }
 

 
    cout << fixed << setprecision(12);
    for(auto idx : order){
        cout << (idx+1);
        for(int j = 0; j < k; j++){
            cout << " " << chosenConfig[idx][j];
        }
        cout << "\n";
    }
 
    return 0;
}
