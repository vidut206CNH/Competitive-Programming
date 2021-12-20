#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	vector<int> a(n + 1);
	vector< vector<int> > dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = a[i];
		for (int j = 2; j <= min(i, k); ++j) {
			for (int l = i - 1; l >= 1; --l) {
				dp[i][j] = max(dp[i][j], dp[l][j - 1] + i * a[i]);
			}
		}
		ans = max(ans, dp[i][k]);
	}
	cout << ans;
}