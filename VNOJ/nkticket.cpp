// link problem: https://oj.vnoi.info/problem/nktick
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

ll MOD = 1000000007;
ll nMax = 1e6 + 1;
int nMaxi = 1e6 + 1;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	vector< vector<int> > dp(n + 1, vector<int>(2, 0));
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][1] = dp[i - 1][0] + b[i - 1] - a[i - 1];
		if (i == 2) dp[i][0] = a[i] + a[i - 1];
	}
	cout << min(dp[n][0], dp[n][1]);
}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	while (t) {
		solve();
		--t;
	}
	return 0;
}