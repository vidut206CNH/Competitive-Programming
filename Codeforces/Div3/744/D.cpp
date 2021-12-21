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

bool cmp(const p64 &a, const p64 &b) {
	return (a.fi > b.fi);
}

void solve() {
	ll n, ans = 0, x;
	cin >> n;
	vector<pair<ll, ll> > p, res;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		p.pb({x, i + 1});
	}
	sort(p.begin(), p.end(), cmp);
	int r = p.size() - 1;
	while (r > 0) {
		while (p[r].fi == 0 && r > 0) --r;
		sort(p.begin(), p.begin() + r + 1, cmp);
		for (int i = 0; i < p[1].fi; ++i) res.pb({p[1].se, p[0].se});
		ans += p[1].fi;
		p[0].fi -= p[1].fi;
		p[1].fi = 0;
	}
	cout << ans << '\n';
	for (auto x : res) {
		cout << x.fi << ' ' << x.se << '\n';
	}
}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	while (t) {
		solve();
		//cout << '\n';
		--t;
	}
	return 0;
}