// link problem: https://oj.vnoi.info/problem/fct020_balloon
// vidut_206_CNH

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, m, k, ans = 0;
	cin >> n >> m >> k;
	vector<ll> a(n + 1);
	vector< vector<ll> > dp(n + 1, vector<ll>(k + 1, 0));
	for (ll i = 1; i <= n; ++i) cin >> a[i];
	for (ll i = 1; i <= n; ++i) {
		dp[i][1] = a[i];
		for (ll j = 2; j <= min(i, k); ++j) {
			for (ll l = i - 1; l >= max(i - m, 1LL); --l) {
				dp[i][j] = max(dp[i][j], dp[l][j - 1] + j * a[i]);
			}
		}
		ans = max(ans, dp[i][k]);
	}
	cout << ans;
}