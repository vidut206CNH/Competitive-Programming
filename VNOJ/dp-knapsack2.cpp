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
const ll nMax = 1e5 + 5;
ll maxx = 1e9 + 3;
void solve() {
	ll n, w, wi, vi;
	cin >> n >> w;
	vector<ll> dp(nMax + 1, maxx);
	dp[0] = 0LL;
	for (int i = 0; i < n; ++i) {
		cin >> wi >> vi;
		//dp[vi] = min(dp[vi], wi);
		for (ll j = nMax; j >= vi; --j) {
			dp[j] = min(dp[j - vi] + wi, dp[j]);
			//cout << dp[j] << '\n';
		}
		//dp[vi] = min(dp[vi], wi);
		//cout << '\n';
	}
	for (ll i = nMax; i > 0; --i) {
		if (dp[i] <= w) {
			cout << i;
			return;
		}
	}
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