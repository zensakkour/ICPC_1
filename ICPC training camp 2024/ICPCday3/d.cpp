#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define decimal long double
#define punt pair<decimal,decimal>
#define richting punt
#define teruggeven(x) cout << setprecision(14) << x << "\n"; return

bool eqAttained(vector<punt>& v, decimal compLength, decimal& solution)
{
    decimal functionEvaluation = (decimal)(-1) * 1000 * 1000 * 1000 * 1000;
    for (int i = 0; i < v.size(); i++)
    {
        decimal newEv = v[i].second + 1 / compLength * v[i].first;
        if (newEv < functionEvaluation)
        {
            punt p1 = v[i-1];
            punt p2 = v[i];
            decimal dm = abs(p1.first-p2.first) + abs(p1.second-p2.second);
            decimal de = sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
            solution = min(solution, dm / de);
            return true;
        }
        functionEvaluation = newEv;
    }
    return false;
}

void process(vector<punt>& v, decimal& solution)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].first == v[i+1].first)
        {
            solution = 1;
            return;
        }
    }
    decimal L = 0, R = 1;
    for (int i = 0; i < 45; i++)
    {
        if (eqAttained(v, (L + R) / 2, solution))
        {
            R = (L + R) / 2;
        }
        else
        {
            L = (L + R) / 2;
        }
    }
    
}

void reflect(vector<punt>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i].second *= -1;
    }
}

void rotate(vector<punt>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        auto aux = v[i].second;
        v[i].second = v[i].first;
        v[i].first = -aux;
    }
}
//setprecision(12) << (1 + solution) / sqrt(solution * solution + 1)
int main()
{
    int n; cin >> n;
    vector<punt> v(n);
    for (int i = 0; i < n; i++)
    {
        lli x,y; cin >> x >> y;
        v[i].first = x; v[i].second = y;
    }
    decimal solution = 2;
    process(v,solution);
    reflect(v);
    process(v,solution);
    rotate(v);
    process(v,solution);
    reflect(v);
    process(v,solution);
    //assert(1 <= solution && sqrt((decimal)(2)) >= solution);
    cout << setprecision(16) << solution << "\n";
}