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
	ll n, m, maxx = 0, sum = 0, x, y;
	cin >> n;
	vector<ll> a(n);
	for (auto &x : a) {
		cin >> x;
		maxx = max(x, maxx);
		sum += x;
	}
	sort(a.begin(), a.end());
	cin >> m;
	vector< pair<ll, ll> > dra;
	for (ll i = 0; i < m; ++i) {
		cin >> x >> y;
		dra.pb({x, y});
	}
	for (ll i = 0; i < m; ++i) {
		ll cnt = 0;
		auto it = lower_bound(a.begin(), a.end(), dra[i].fi);
		if (it == a.end()) {
			cnt = (dra[i].fi - * (it - 1) + max(dra[i].se - sum + * (it - 1), 0LL));
		}
		else if (it == a.begin()) {
			cnt = max(0LL, dra[i].se - sum + *it);
		}
		else {
			cnt = min(max(0LL, dra[i].se - sum + *it), (dra[i].fi - * (it - 1)) + max(0LL, dra[i].se - sum + * (it - 1)));
		}
		cout << cnt << '\n';
	}

}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	while (t) {
		solve();
		//cout << '\n';
		--t;
	}
	return 0;
}