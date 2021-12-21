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
#define int long long
const ll MOD = 1000000007;
const ll nMax = 1e6 + 1;

// int lwb(const vector<p64> &b, ll k) {
// 	int l = 0, r = b.size() - 1, mid;
// 	int ans = r;
// 	while (l <= r) {
// 		mid = (l + r) / 2;
// 		if (b[mid].fi == k) return mid;
// 		if (b[mid].fi > k) {
// 			ans = min(ans, mid);
// 			r = mid - 1;
// 		}
// 		else l = mid + 1;
// 	}
// 	return ans;
// }


bool cmp(const p64 &a, const p64 &b) {
	return (a.fi < b.fi);
}

void solve() {
	int m, n, l, r, x;
	cin >> m >> n;
	vector< pii >p(m);
	for (int i = 0; i < m; ++i) {
		cin >> p[i].fi;
		p[i].se = 0;
	}
	//sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < n; ++i) {
		cin >> l >> r >> x;
		for (auto &t : p) {
			if (l <= t.fi && t.fi <= r) {
				t.se += (((t.fi - l) % 2 == 0) ? x : -x);
			}
		}
	}
	for (auto t : p) {
		cout << t.se << '\n';
	}
}


int main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}