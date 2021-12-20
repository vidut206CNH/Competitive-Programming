#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<long long> dp(n + 1, -1);
	for (long long i = min(a, min(b, c)); i <= n; ++i) {
		if (i == a || i == b || i == c) dp[i] = 1LL;
		dp[i] = max(max(dp[i], dp[max(0LL, i - a)] + 1), max(dp[max(0LL, i - b)] + 1, dp[max(0LL, i - c)] + 1));
		if (dp[i] == 0) dp[i] -= 1;
	}
	cout << dp[n];
}