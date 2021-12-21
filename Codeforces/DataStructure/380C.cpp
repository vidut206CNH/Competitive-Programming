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
typedef pair<int, p32> node;
node st[4 * nMax];
string s;

void build(int id, int l, int r) {
	if (l == r) {
		if (s[l - 1] == '(') st[id] = {0, {1, 0}};
		else st[id] = {0, {0, 1}};
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	int tmp = min(st[id * 2].se.fi, st[id * 2 + 1].se.se);
	st[id].fi = st[id * 2].fi + st[id * 2 + 1].fi + tmp;
	st[id].se.fi = st[id * 2].se.fi + st[id * 2 + 1].se.fi - tmp;
	st[id].se.se = st[id * 2].se.se + st[id * 2 + 1].se.se - tmp;
}

node query(int id, int &u, int &v, int l, int r) {
	if (u > r || l > v) return {0, {0, 0}};
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	node le = query(id * 2, u, v, l, mid);
	node ri = query(id * 2 + 1, u, v, mid + 1, r), ans;
	int tmp = min(le.se.fi, ri.se.se);
	ans.fi = le.fi + ri.fi + tmp;
	ans.se.fi = le.se.fi + ri.se.fi - tmp;
	ans.se.se = le.se.se + ri.se.se - tmp;
	return ans;

}

void solve() {
	cin >> s;
	int n = s.size();
	build(1, 1, n);
	//cout << st[5].fi << '\n';
	int q, u, v;
	cin >> q;
	while (q) {
		cin >> u >> v;
		cout << 2 * query(1, u, v, 1, n).fi << '\n';
		--q;
	}
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