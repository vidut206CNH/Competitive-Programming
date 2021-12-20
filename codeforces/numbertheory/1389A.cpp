#include<bits/stdc++.h>

using namespace std;

void solve() {
	int l, r;
	cin >> l >> r;
	if (r / l < 2) cout << -1  << ' ' << -1 << '\n';
	else {
		cout << l << ' ' << l * 2 << '\n';
	}
}


int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}