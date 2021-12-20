/*
	link problem: https://oj.vnoi.info/problem/haoi08_gh
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
	if (a.fi == b.fi) return (a.se > b.se);
	return (a.fi > b.fi);
}

void solve() {
	vector< p64 > p(3);
	ll sum = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> p[i].fi >> p[i].se;
		sum += p[i].fi * p[i].se;
		if (p[i].fi < p[i].se) swap(p[i].fi, p[i].se);
	}
	ll t = sqrt(sum);
	if (t * t != sum) {
		cout << 0;
		return;
	}
	sort(p.begin(), p.end(), cmp);
	if (p[0].fi == p[1].fi && p[1].fi == p[2].fi && p[0].se + p[1].se + p[2].se == p[0].fi) {
		cout << p[0].fi;
		return;
	}
	if (p[1] == p[2] && ((p[1].fi + p[2].fi == p[0].fi && p[1].se + p[0].se == p[0].fi) || (p[1].se + p[2].se == p[0].fi && p[1].fi + p[0].se == p[0].fi))) {
		cout << p[0].fi;
		return;
	}
	if (p[1].fi + p[2].se == p[0].fi && p[1].se + p[0].se == p[0].fi && p[1].se == p[2].fi) {
		cout << p[0].fi;
	}
	else cout << 0;

//&& ((p[1].fi + p[2].fi == p[0].fi && p[1].se + p[0].se == p[0].fi) || (p[1].se + p[2].se == p[0].fi && p[1].fi + p[0].se == p[0].fi))

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