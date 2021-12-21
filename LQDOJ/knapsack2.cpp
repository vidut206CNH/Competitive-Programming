#include<bits/stdc++.h>

using namespace std;

const long long nMax = 1e5 + 1;
const long long INF = 2e18;

void solve() {
	long long n, w, sum = 0, Max = 0;
	cin >> n >> w;
	vector<long long> dp(nMax + 1, INF), we(n + 1), va(n + 1);
	dp[0] = 0;
	for (long long i = 1; i <= n; ++i) {
		cin >> we[i] >> va[i];
		sum += va[i];
		for (long long k = sum; k >= va[i]; --k) {
			dp[k] = min(dp[k], dp[k - va[i]] + we[i]);
			if (k > Max && dp[k] <= w) {
				Max = k;
			}
		}
	}
	cout << Max;
}
int main() {
	solve();
}