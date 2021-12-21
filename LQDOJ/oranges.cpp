// link problem: https://lqdoj.edu.vn/problem/cd20bonus
// vidut_206_CNH
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
	ll n, k, ans = 0;
	cin >> n >> k;
	ll a[n + 1][n + 1], dp[n + 1][n + 1];
	memset(a, 0LL, sizeof(a));
	memset(dp, 0LL, sizeof(dp));
	vector<v64> sum_r(n + 1, v64(n + 1, 0)), sum_c(n + 1, v64(n + 1, 0));
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= n; ++j) {
			cin >> a[i][j];
			sum_r[i][j] = sum_r[i][j - 1] + a[i][j];
			sum_c[i][j] =  sum_c[i - 1][j] + a[i][j];
		}
	}
	for (ll i = 1; i <= k; ++i) {
		dp[k][k] += sum_r[i][k];
		ans = max(ans, dp[k][k]);
	}
	for (ll i = k + 1; i <= n; ++i) {
		dp[i][k] = dp[i - 1][k] - sum_r[i - k][k] + sum_r[i][k];
		ans = max(ans, dp[i][k]);
	}
	for (ll i = k; i <= n; ++i) {
		for (ll j = k + 1; j <= n; ++j) {
			dp[i][j] = dp[i][j - 1] - (sum_c[i][j - k] - sum_c[i - k][j - k]) + (sum_c[i][j] - sum_c[i - k][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}


int main() {
	fast_cin();
	ll t = 1;
	// cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}