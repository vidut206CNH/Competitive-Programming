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

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return (a.fi < b.fi);
}

void solve() {
	ll n, m, x, y, ans = 0, tmp;
	cin >> n >> m;
	vector< pair<ll, ll> > a;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		a.pb({x, y});
	}
	sort(a.begin(), a.end(), cmp);
	int i = 0;
	while (i < n && m) {
		tmp = m / a[i].fi;
		m %= a[i].fi;
		if (tmp > a[i].se) {
			m += a[i].fi * (tmp - a[i].se);
			tmp = a[i].se;
		}
		ans += tmp;
		i++;
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