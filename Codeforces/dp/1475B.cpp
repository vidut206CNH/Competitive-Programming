#include<bits/stdc++.h>

using namespace std;

const int nMax = 1e6 + 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	vector<bool> dp(nMax, 0);
	dp[2020] = 1;
	dp[2021] = 1;
	for (int i = 2022; i <= nMax; ++i) {
		dp[i] = (dp[i - 2020] || dp[i - 2021]);
	}
	while (t) {
		int n;
		cin >> n;
		cout << ((dp[n]) ? "YES" : "NO");
		cout << '\n';
		--t;
	}
}