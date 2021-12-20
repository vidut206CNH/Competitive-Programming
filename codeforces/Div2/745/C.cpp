/*
	link problem:
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
	char c;
	cin >> m >> n;
	ll a[m + 1][n + 1];
	vv64 sumr(m + 1, v64(n + 1, 0LL)), sumc(m + 1, v64(n + 1, 0LL)), sumf(m + 1, v64(n + 1, 0LL));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> c;
			a[i][j] = (ll)(c - '0');
			sumc[i][j] = sumc[i - 1][j] + a[i][j];
			sumr[i][j] = sumr[i][j - 1] + a[i][j];
		}
		cin.ignore();
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			sumf[i][j] = sumf[i - 1][j] + sumf[i][j - 1] - sumf[i - 1][j - 1] + a[i][j];
		}
	}
	ll ans = INF;
	for (int i = 1; i <= m - 4; ++i) {
		for (int j = 1; j <= n - 3; ++j) {
			ll tmp = (3 - sumc[i + 3][j] + sumc[i][j]) + (3 - sumc[i + 3][j + 3] + sumc[i][j + 3]) + (2 - sumr[i][j + 2] + sumr[i][j]) + (2 - sumr[i + 4][j + 2] + sumr[i + 4][j]) + (sumf[i + 3][j + 2] - sumf[i][j + 2] - sumf[i + 3][j] + sumf[i][j]);
			cout << (sumf[i + 3][j + 2] - sumf[i][j + 2] - sumf[i + 3][j] + sumf[i][j]) << ' ';
			cout << tmp << ' ' << i << ' ' << j << '\n';
			ans = min(tmp, ans);
		}
	}
	cout << ans;
}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}