#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> resultOrder;

    long long maxValue = A[0];

    for (int i = n - 1; i > 0; --i) {
        maxValue = maxValue - A[i];
        resultOrder.push_back(i + 1); 
    }

    cout << maxValue << endl;
    for (int i = resultOrder.size() - 1; i >= 0; --i) {
        cout << resultOrder[i] << endl;
    }

    return 0;
}
