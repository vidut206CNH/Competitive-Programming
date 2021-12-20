// link problem: https://codeforces.com/gym/331607/problem/2C
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

const ll MOD = 1000000007;
const ll nMax = 1e6 + 1;

void solve() {
	vector<ll> a(5, 0);
	ll n, ans = 0, x;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		cin >> x;
		a[x]++;
	}
	ans += a[4];
	ans += min(a[3], a[1]);
	if (a[3] > a[1]) {
		ans += (a[3] - a[1]);
		a[1] = 0;
	}
	else a[1] -= a[3];
	ans += a[2] / 2;
	if (a[2] % 2) {
		ans++;
		if (a[1] > 0) a[1] -= min(2LL, a[1]);
	}
	ans += (a[1] / 4 + (a[1] % 4 != 0));
	cout << ans;
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