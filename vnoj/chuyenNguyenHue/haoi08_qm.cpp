/*
	link problem: https://oj.vnoi.info/problem/haoi08_qm
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
	int m, n;
	cin >> m >> n;
	ll a[m][n];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	vv64 dp(m, v64(n));
	ll ans = 0, tmp;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = a[i][j];
			tmp = 0;
			if (i > 1) {
				if (j > 0)tmp = max(tmp, dp[i - 2][j - 1]);
				if (j < n - 1) tmp = max(tmp, dp[i - 2][j + 1]);
			}
			if (i > 0) {
				if (j > 1)tmp = max(tmp, dp[i - 1][j - 2]);
				if (j < n - 2) tmp = max(tmp, dp[i - 1][j + 2]);
			}
			dp[i][j] += tmp;
			ans = max(dp[i][j], ans);
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