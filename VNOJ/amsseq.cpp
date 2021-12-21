/*
	link problem: https://oj.vnoi.info/problem/amsseq
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
	int n, k, ans = -nMax;
	cin >> n >> k;
	vector<int> a(n + 1, 0), dp(n + 1, -nMax);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 1; j <= min(k, i); ++j) {
			dp[i] = max(dp[i], dp[i - j]);
		}
		dp[i] += a[i];
		ans = max(dp[i], ans);
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