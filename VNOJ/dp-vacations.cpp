/*
	link problem: https://oj.vnoi.info/problem/atcoder_dp_c
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
	int n;
	cin >> n;
	vector< vector<ll> > dp(n, vector<ll>(3));
	for (int i = 0; i < n; ++i) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		if (i > 0) {
			for (int j = 0; j < 3; ++j) {
				ll tmp = 0;
				for (int k = j + 1; k <= j + 2; ++k) {
					tmp = max(tmp, dp[i - 1][k % 3]);
				}
				dp[i][j] += tmp;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 3; ++i) ans = max(ans, dp.back()[i]);
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