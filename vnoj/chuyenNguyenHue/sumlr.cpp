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
const ll nMax = 1e5 + 3;

ll pref[nMax], a[nMax];
ll st[4 * nMax];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = pref[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

ll query(int id, int u, int v, int l, int r) {
	if (r < u || v < l) return INF;
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return min(query(id * 2, u, v, l, mid), query(id * 2 + 1, u, v, mid + 1, r));
}

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	build(1, 1, n);
	ll tmp, ans = -INF;
	for (int i = n; i >= l; --i) {
		tmp = pref[i] - query(1, max(0, i - r), i - l, 1, n);
		ans = max(ans, tmp);
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