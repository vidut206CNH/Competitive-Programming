#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	char c;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		if (c == 'L' || c == 'R') cout << c;
		if (c == 'U') cout << 'D';
		if (c == 'D') cout << 'U';
	}
	cout << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}