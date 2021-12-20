/*
	link problem: https://codeforces.com/contest/1359/problem/B
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
int n, m, u, v;
char a[1003][1003];
void solve() {
	int cnt1 = 0, cnt2 = 0;
	cin >> n >> m >> u >> v;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j < m - 1 && a[i][j] == a[i][j + 1] && a[i][j] == '.') {
				cnt2++;
				++j;
			}
			else if (a[i][j] == '.') cnt1++;
		}
	}
	if (v < 2 * u) {
		cout << 1LL * cnt1*u + cnt2*v;
	}
	else cout << 1LL * (cnt1 + 2 * cnt2)*u;
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