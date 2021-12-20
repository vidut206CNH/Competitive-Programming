#include<bits/stdc++.h>

using namespace std;

int main() {
	long long  n, sum = 0, s, x;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> x;
			a[i] += x;
		}
		sum += a[i];
	}
	s = sum / (2 * n - 2);
	for (int i = 0; i < n; ++i) {
		cout << (a[i] - s) / (n - 2) << ' ';
	}

}