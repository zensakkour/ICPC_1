#ifdef __GNUC__
#  if defined(__x86_64__) && !defined(__MINGW32__)
#    pragma GCC optimize("Ofast,unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#  endif
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define endl '\n'

using i128 = __int128_t;

const int INF64 = (int)4e18;

static inline int cmpFrac(i128 a, i128 b, i128 c, i128 d){
    i128 lhs = a *d;
    i128 rhs = c * b;
    if (lhs == rhs) return 0;
    return (lhs < rhs ? -1 : 1);
}

struct State{
    int side;
    int vx,vy;
    long long R;

    bool operator<(State const& o) const noexcept{
        if (side!= o.side) return side < o.side;
        if (vx != o.vx) return vx < o.vx;
        if (vy != o.vy) return vy < o.vy;
        return R <o.R;
    }
};

long long solve_one(long long n, long long x0, long long y0, long long vx0, long long vy0){
    long long R =(long long)((i128)x0 * vy0 - (i128)y0 * vx0);
    long long vx =vx0, vy = vy0;
    long long hits = 0;

    ++hits;
    R = n * (vy - vx) - R;
    long long tmp = vx;
    vx = -vy;
    vy = -tmp;
    int side = 0;

    set<State> seen;
    seen.insert({side, vx, vy, R});

    for (;;){
        if (side ==0){
            long long S= vx + vy;
            long long x_num = R + n * vx;
            long long y_num = n *vy - R;

            i128 D = (i128)(-vy) * x_num - (i128)(-vx) * y_num;
            if (D == 0) return hits;

            if ((S < 0&& D > 0)|| (S > 0 && D < 0)){
                ++hits;
                R = -R;
                vx = -vx;
                side = 1;
            } else {
                ++hits;
                R =-R;
                vy = -vy;
                side = 2;
            }
        } else if (side == 1){
            long long y_num =-R;
            bool haveY = (vy < 0);
            bool haveH = (vx + vy > 0);
            int nxt = -1;

            if (haveY && haveH){
                i128 ty_num =(i128)y_num;
                i128 ty_den =(i128)vx * (-vy);
                i128 th_num= (i128)n * vx + R;
                i128 th_den = (i128)vx *(vx + vy);

                int c = cmpFrac(ty_num, ty_den, th_num, th_den);
                if (c == 0) return hits;
                nxt = (c < 0 ? 2 : 0);
            } else if (haveY){
                nxt=2;
            } else if (haveH){
                nxt = 0;
            } else {
                return -1;
            }

            if (nxt == 2){
                ++hits;
                R = -R;
                vy =-vy;
                side= 2;
            } else {
                ++hits;
                R = n * (vy - vx) - R;
                long long t = vx;
                vx = -vy;
                vy = -t;
                side = 0;
            }
        } else {
            long long x_num= R;
            bool haveX = (vx < 0);
            bool haveH= (vx+ vy > 0);
            int nxt = -1;

            if (haveX && haveH){
                i128 tx_num= (i128)x_num;
                i128 tx_den =(i128)vy * (-vx);
                i128 th_num = (i128)n * vy - R;
                i128 th_den = (i128)vy * (vx + vy);

                int c = cmpFrac(tx_num, tx_den, th_num, th_den);
                if (c == 0) return hits;
                nxt = (c< 0 ? 1 : 0);
            } else if (haveX){
                nxt =1;
            } else if (haveH){
                nxt = 0;
            } else {
                return -1;
            }

            if (nxt== 1){
                ++hits;
                R =-R;
                vx = -vx;
                side = 1;
            } else {
                ++hits;
                R = n* (vy - vx) - R;
                long long t = vx;
                vx =-vy;
                vy = -t;
                side = 0;
            }
        }

        State cur{side,(int)vx, (int)vy, R};
        if (!seen.insert(cur).second) return -1;
    }
}

void solve(){
    long long n, x, y, vx, vy;
    cin >> n >> x >> y >> vx >> vy;
    cout << solve_one(n,x, y, vx, vy) << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
