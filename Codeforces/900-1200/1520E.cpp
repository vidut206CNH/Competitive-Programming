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
	ll n, ans = INF;
	cin >> n;
	string s;
	cin >> s;
	vector<ll> pref(n + 1, 0), suf(n + 1, 0);
	vector<pair<int, pair<ll, ll>> > pr;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			pair<int, pair<ll, ll> > p;
			p.fi = i;
			if (!pr.empty()) p.se.fi =  (i - pr.back().fi - 1) * pr.size() + pr.back().se.fi;
			else p.se.fi = 0;
			p.se.se = 0;
			pr.pb(p);
		}
	}
	for (int i = pr.size() - 2; i >= 0; --i) {
		pr[i].se.se = pr[i + 1].se.se + (pr.size() - i - 1) * (pr[i + 1].fi - pr[i].fi - 1);
	}
	bool chk = 0;
	for (int i = 0; i < pr.size(); ++i) {
		ans = min(ans, pr[i].se.fi + pr[i].se.se);
		chk = 1;
	}
	if (chk) cout << ans;
	else cout << 0;
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