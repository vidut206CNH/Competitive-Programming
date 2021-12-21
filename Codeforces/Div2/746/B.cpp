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
	int n, k;
	cin >> n >> k;
	vector<p32> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (i != a[i].se && ((i + k > n - 1 && i - k < 0) || (a[i].se + k > n - 1  && a[i].se - k < 0))) {
			cout << "NO";
			return;
		}
		//cout << i << ' ' << a[i].se  << '\n';
	}
	cout << "YES";
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