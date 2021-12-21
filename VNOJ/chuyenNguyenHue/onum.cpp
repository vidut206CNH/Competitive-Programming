/*
	link problem: https://oj.vnoi.info/problem/onum
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
ll a[20];

ll powz(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void sol1() {
	a[1] = 9;
	for (int i = 2; i <= 19; ++i) {
		a[i] = 9 * powz(10, i - 2) + a[i - 1];
	}
}


ll cnt(ll n) {
	ll cnt = 0;
	if (n == 0) return 1;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

ll cal(ll n) {
	ll t = cnt(n);
	if (t == 1) return n;
	ll res = a[t - 1];
	ll tmp = n / powz(10, t - 1);
	if (t == 2) {
		if (tmp > n % 10) --tmp;
		res += tmp;
		return res;
	}
	if (tmp > n % 10) {
		n -= (10 + n % 10 - tmp);
	}
	if (cnt(n) < t) return res;
	res += tmp * powz(10, t - 2) - (powz(10, t - 2) - ((n % powz(10, t - 1)) / 10) - 1);
	return res;

}


void solve() {
	ll l, r;
	cin >> l >> r;
	cout << cal(r) - cal(l - 1);
}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	sol1();
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}