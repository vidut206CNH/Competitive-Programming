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

ll powz(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void solve() {
	ll a, b, k, cnt = 0;
	cin >> a >> b >> k;
	for (ll i = cbrt(b); powz(i, 3) >= a; --i) {
		for (ll j = sqrt(powz(i, 3)); j * j >= max(a, powz(i, 3) - k); --j) {
			cnt++;
			//cout << i << ' ' << j << '\n';
		}
		for (ll j = sqrt(min(powz(i, 3) + k, b)); j * j > powz(i, 3); --j) {
			cnt++;
			//cout << i << ' ' << j << '\n';
		}
	}
	cout << cnt;
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