// link problem:
// vidut_206_CNH
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
	int n;
	cin >> n;
	vector<bool> chk(n + 1, 0);
	vector< vector<int> > b(n + 1);
	vector<int> a(n);
	int ans = 0, t = -1, x;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x == 0) {
			b[i] = {0};
		}
		else
		{	vector<int> cur(x);
			for (int j = 0; j < x; ++j) {
				cin >> cur[j];
			}
			b[i] = cur;
		}
	}
	int ti = 1;
	while (ti <= n) {
		for (int i = 1; i <= n; ++i) {
			bool c1 = 1;
			for (int x : b[i]) {
				if (x == 0) {
					chk[i] = 1;
					continue;
				}
				c1 &= chk[x];
			}
			if (c1) {
				chk[i];
				ans++;
			}
			cout << chk[i] << '\n';
		}
		if (ans == n) break;
		ti++;
	}
	if (ans == n) {
		cout << ti;
	}
	else cout << -1;
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