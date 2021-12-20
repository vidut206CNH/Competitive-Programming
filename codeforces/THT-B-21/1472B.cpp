#include<bits/stdc++.h>

using namespace std;

int x;
void solve() {
	int n, c1 = 0, c2 = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum += x;
		if (x == 1) c1++;
		else c2++;
	}
	if (sum % 2 != 0) {
		cout << "NO" << '\n';
		return;
	}
	sum /= 2;
	if (sum % 2 != 0 && c1 == 0) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}