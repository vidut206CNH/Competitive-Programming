#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n), dp(n, 1);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		for (ll j = i - 1; j >= 0; --j) {
			if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}