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
const int nMax = 1e6 + 3;

void solve() {
	int n, m, k;
	string s;
	char c;
	cin >> n >> m >> k;
	pair<int, int> p[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	for (int i = 0; i < m; ++i) {
		cin >> c;
		s += c;
	}
	int pos = 1, ans = 0;
	vector<int> st(nMax);
	for (int i = 1; i <= min(k, nMax); ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'L') pos = p[pos].fi;
			else pos = p[pos].se;
		}
		st[i] = pos;
		for (int j = i - 1; j >= 1; --j) {
			if (st[i] == st[j]) {
				ans = st[j + (k - i) % (i - j)];
				cout << ans;
				return;
			}
		}
		if (i == k) {
			cout << st[i];
			return;
		}
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