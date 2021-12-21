#include<bits/stdc++.h>

using namespace std;


void solve() {
	long long m, n;
	cin >> m >> n;
	long long dp[n + 1][m + 1], a[n + 1];
	for (long long i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i][0] = 1;
		for (long long j = 1; j <= m; ++j) {
			dp[0][j] = 0;
			dp[i][j] = 0;
			if (j >= a[i]) {
				dp[i][j] += dp[i][j - a[i]];
			}
			dp[i][j] += dp[i - 1][j];
		}
	}
	cout << dp[n][m];
}

int main() {
	solve();
}