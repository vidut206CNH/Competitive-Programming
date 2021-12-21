/*
	link problem: https://oj.vnoi.info/problem/qbmax
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b

const ll MOD = 1000000007;
const ll nMax = 1e6 + 1;

void solve() {
	ll n, m, ans = -INF;
	cin >> n >> m;
	ll a[n + 1][m + 1], dp[n + 1][m + 1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = a[i][1];
	}
	for (int j = 2; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			dp[i][j] = dp[i][j - 1] + a[i][j];
			if (i > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
			if (i < n) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
			if (j == m) ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}