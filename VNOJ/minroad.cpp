/*
	link problem: https://oj.vnoi.info/problem/minroad
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
	int n, x, a, b, ans = 1e9 + 3;
	cin >> n >> a >> b;
	pair<int, pair<int, int> > p[n + 1];
	p[0] = {0, {0, 0}};
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].fi >> x;
		p[i].se.fi =  (x == 1);
		p[i].se.se =  (x == 2);
	}
	sort(p, p + n + 1);
	for (int i = 1; i <= n; ++i) {
		p[i].se.fi += p[i - 1].se.fi;
		p[i].se.se += p[i - 1].se.se;
	}
	int i = 1, ta, tb;
	for (int j = n; j >= 2; --j) {
		ta = p[j].se.fi - p[i - 1].se.fi;
		tb = p[j].se.se - p[i - 1].se.se;
		while (i > 0 && (ta < a || tb < b || i >= j)) {
			--i;
			ta = p[j].se.fi - p[i - 1].se.fi;
			tb = p[j].se.se - p[i - 1].se.se;
		}
		while (i < j && ta >= a && tb >= b) {
			ans = min(ans, p[j].fi - p[i].fi);
			i++;
			ta = p[j].se.fi - p[i - 1].se.fi;
			tb = p[j].se.se - p[i - 1].se.se;
			//cout << ans << ' ' << j << '\n';
		}
		if (i == 0) break;
		//cout << ans << ' ' <<  j << ' ' << i << '\n';
	}
	if (ans == 1e9 + 3) cout << -1;
	else cout << ans;
}
/*
10 1
20 2
25 1
30 1
35 2
60 2
65 1
*/

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