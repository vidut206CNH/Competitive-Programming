#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, x, sum = 0;
	cin >> n;
	vector<bool> a(10000, 0);
	a[0] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum += x;
		for (int j = sum; j >= x; --j) {
			a[j] = (a[j - x] || a[j]);
		}
	}
	for (int i = sum / 2; i >= 0; --i) {
		if (a[i]) {
			cout << sum - 2 * i;
			return 0;
		}
	}
}