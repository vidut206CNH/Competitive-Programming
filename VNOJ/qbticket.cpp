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
	pair<ll, ll> p[3];
	for (int i = 0; i < 3; ++i) cin >> p[i].fi;
	for (int i = 0; i < 3; ++i) cin >> p[i].se;
	int n, st, ed;
	ll tmp;
	cin >> n >> st >> ed;
	vector<ll> a(n + 1), dp(n + 1, INF);
	dp[st] = 0;
	for (int i = 2; i <= n; ++i) cin >> a[i];
	for (int i = st + 1; i <= ed; ++i) {
		for (int j = i - 1; j >= st; --j) {
			tmp = 0;
			for (int k = 0; k < 3; ++k) {
				if (a[i] - a[j] <= p[k].fi) {
					tmp = p[k].se;
					break;
				}
			}
			if (tmp) dp[i] = min(dp[i], dp[j] + tmp);
			else break;
		}
	}
	cout << dp[ed];
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