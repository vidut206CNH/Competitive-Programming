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
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n + 1), pref(n + 2, 0), suff(n + 2, 0);

	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = gcd(pref[i - 1], a[i]);
	}
	if (n == 1) {
		cout << 1000000000;
		return;
	}
	for (ll i = n; i > 0; --i) {
		suff[i] = gcd(suff[i + 1], a[i]);
	}
	for (ll i = 1; i <= n; ++i) {
		ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
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