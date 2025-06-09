#include <bits/stdc++.h>
using namespace std;

int main() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	int s1, e1, s2, e2, s3, e3;
	cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;

	int cost = 0;
	for(int t = 1; t <= 100; t++) {
		int parked = (s1 <= t && t < e1) + (s2 <= t && t < e2) + (s3 <= t && t < e3);
		if(parked == 1) cost += p1;
		if(parked == 2) cost += 2 * p2;
		if(parked == 3) cost += 3 * p3;
	}

	cout << cost << endl;
}
