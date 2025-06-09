#ifdef __GNUC__
#  if defined(__x86_64__) && !defined(__MINGW32__)
#    pragma GCC optimize("Ofast,unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#  endif
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

using i128 = __int128_t;

static inline int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t x1, y1, g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

static inline int64_t mod_inv(int64_t a, int64_t mod) {
    int64_t x,y;
    exgcd(a, mod, x, y);
    x%= mod;
    if (x < 0) x += mod;
    return x;
}

static bool crt(int64_t a1, int64_t m1, int64_t a2, int64_t m2, int64_t &x, int64_t &lcm) {
    int64_t x1, y1, g = exgcd(m1, m2, x1, y1);
    if ((a2 - a1) % g) return false;
    int64_t mod = m2 / g;
    i128 k = (i128)(a2 - a1)/ g * (x1 % mod);
    k %= mod;
    if (k < 0) k += mod;
    lcm = m1 / g *m2;
    x = (a1 + (i128)m1 * k) % lcm;
    if (x < 0) x += lcm;
    return true;
}

long long solve_one(long long n, long long x, long long y, long long vx, long long vy) {
    long long gdir = std::gcd(vx, vy);
    vx /=gdir;
    vy /= gdir;

    long long g1 = std::gcd(vx, n);
    if ((n - x) %g1) return -1;
    long long m1 = n / g1;
    long long a1 = ((n - x) / g1 * mod_inv(vx / g1, m1)) % m1;

    long long g2= std::gcd(vy, n);
    if ((n - y) % g2) return -1;
    long long m2 = n / g2;
    long long a2 = ((n - y) / g2 * mod_inv(vy / g2, m2)) % m2;

    long long t, lcm;
    if (!crt(a1, m1, a2, m2, t, lcm)) return -1;
    if (t == 0) t = lcm;

    long long tx = (x + (i128)vx * t) / n;
    long long ty = (y + (i128)vy * t) / n;

    long long hits = (tx - 1) + (ty - 1) + (tx + ty) / 2 + std::llabs(tx - ty) / 2;
    return hits;
}

void solve() {
    long long n, x, y, vx, vy;
    cin >> n >> x >> y >> vx >> vy;
    cout << solve_one(n, x, y, vx, vy) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
