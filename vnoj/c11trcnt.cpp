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

ll powz(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}


bool chk(const p64 &a, const p64 &b, const p64 &c) {
	if ((a.se - b.se) * (a.fi - c.fi) == (a.se - c.se) * (a.fi - b.fi)) return 0;
	return 1;
}


void solve() {
	ll n, cnt = 0;
	cin >> n;
	pair<ll, ll> p[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	vector<ll> a(n + 1, 0);
	for (int i = 1; i <= n - 2; ++i) {
		for (int j = i + 1; j <= n - 1; ++j) {
			for (int l = j + 1; l <= n; ++l) {
				if (chk(p[i], p[j], p[l])) {
					++a[i];
					++a[j];
					++a[l];
					++cnt;
				}
				//cout << chk(p[i], p[j], p[l]) << ' ' << i << ' ' << j << ' ' << l << '\n';
			}
		}
	}
	ll minn = 1e9 + 3, minnid;
	for (int i = 1; i <= n; ++i) {
		if (minn > a[i]) {
			minn = a[i];
			minnid = i;
		}
	}
	cout << cnt << ' ' << minnid;

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