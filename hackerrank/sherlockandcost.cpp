#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector< vector<int> > dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i].resize(2);
		if (i > 1) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i - 1] - 1);
			dp[i][1] = max(dp[i - 1][0] + a[i] - 1, dp[i - 1][1] + abs(a[i] - a[i - 1]));
		}

	}
	cout << max(dp[n][1], dp[n][0]) << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}