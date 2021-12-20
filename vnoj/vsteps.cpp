/*
	link problem: https://oj.vnoi.info/problem/vsteps
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

const ll MOD = 14062008;
const ll nMax = 1e6 + 1;
int n, k, x;


void solve() {
	cin >> n >> k;
	vector<bool> a(n + 1, 0);
	for (int i = 0; i < k; ++i) {
		cin >> x;
		a[x] = 1;
	}
	vector<ll> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i]);
		else {
			if (i > 1) dp[i] = (dp[i] + dp[i - 1]) % MOD;
			if (i > 2) dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}
	cout << dp[n] % MOD;


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