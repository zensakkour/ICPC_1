#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

struct Log {
    ll y1, y2;
};

ll calculate_cut_length(double y, const vector<Log>& logs) {
    ll total_sum = 0;
    for (const auto& log : logs) {
        if (y < log.y1) {
            continue;
        } else if (y > log.y2) {
            total_sum += (log.y2 - log.y1);
        } else {
            total_sum += min(y - log.y1, log.y2 - y);
        }
    }
    return total_sum;
}

double find_min_cut_y(int n, ll k, const vector<Log>& logs) {
    set<double> unique_y;
    for (const auto& log : logs) {
        unique_y.insert(log.y1);
        unique_y.insert(log.y2);
    }

    vector<double> sorted_y(unique_y.begin(), unique_y.end());
    sort(sorted_y.begin(), sorted_y.end());

    double result = -1;
    for (size_t i = 0; i < sorted_y.size(); ++i) {
        double y = sorted_y[i];
        if (calculate_cut_length(y, logs) == k) {
            result = y;
            break;
        }

        if (i < sorted_y.size() - 1) {
            double lo = sorted_y[i];
            double hi = sorted_y[i + 1];
            while (hi - lo > 1e-15) {
                double mid = (lo*1.0 + hi*1.0) / 2.0;
                ll cut_sum = calculate_cut_length(mid, logs);
                if (cut_sum < k) {
                    lo = mid;
                } else {
                    hi = mid;
                }
                if (abs(cut_sum-k) <=1e-4  ) {
                    result = mid;
                    break;
                }
            }
            cout <<hi<<" "<<lo<<endl;
            if (result != -1) break;
        }
    }

    return result;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<Log> logs(n);
    for (int i = 0; i < n; ++i) {
        ll x1, x2;
        cin >> x1 >> logs[i].y1 >> x2 >> logs[i].y2;
    }

    double result = find_min_cut_y(n, k, logs);
    if (result == -1) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << result << endl;
    }

    return 0;
}
