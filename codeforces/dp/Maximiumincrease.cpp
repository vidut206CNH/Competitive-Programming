#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, ans = 1, x, y;
	cin >> n;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x > y) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
		ans = max(ans, dp[i]);
		y = x;
	}
	cout << ans;
}