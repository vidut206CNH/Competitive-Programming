// link problem:
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
const ll nMax = 1e9 + 1;

bool cmp( const p32 &a, const p32 &b) {
	return (a.fi > b.fi);
}

void solve() {
	int n, m, x, ans = 0;
	cin >> n >> m;
	n -= m;
	vector<p32> a;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		a.push_back({b[i], 1});
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), greater<int>());
	while (n) {
		int i = 0;
		ans = 0;
		while (i < m && n > 0 && a[i].fi >= ans) {
			a[i].se++;
			a[i].fi = b[i] / a[i].se + (b[i] % a[i].se != 0);
			--n;
			ans = max(ans, a[i].fi);
			i++;
		}
		// i = 0;
		// ans = -nMax;
		// while (i < m && n > 0 && a[i].fi >= ans) {
		// 	bool chk = 0;
		// 	a[i].se++;
		// 	a[i].fi = b[i] / a[i].se + (b[i] % a[i].se != 0);
		// 	--n;
		// 	ans = max(ans, a[i].fi);
		// 	i++;
		// }
	}
	ans = 0;
	for (int i = 0; i < m; ++i) ans = max(ans, a[i].fi);
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