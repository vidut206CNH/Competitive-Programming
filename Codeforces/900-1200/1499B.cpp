/*
	link problem: https://codeforces.com/contest/1499/problem/B
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
	string s;
	cin >> s;
	int n = s.size();
	bool dp[n];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (s[i] >= s[i - 1]) {
			dp[i] |= dp[i - 1];
		}
		if (s[i] >= s[i - 2]) dp[i] |= dp[i - 2];
		//cout << dp[i] << '\n';
	}
	bool ans = (dp[n - 1] || dp[n - 2]);
	cout << ((ans) ? "YES" : "NO");

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