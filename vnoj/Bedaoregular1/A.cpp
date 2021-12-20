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
	ll a1, b1 = 0, a2, b2 = 0, t, res1 = nMax, res2 = nMax;
	string s;
	cin >> a1;
	if (a1 == 0) {
		res1 = a1;
		cin >> s;
	}
	else cin >> b1;
	cin >> a2;
	if (a2 == 0) {
		res2 = a2;
		cin >> s;
	}
	else cin >> b2;
	t = min(b1, b2);
	b1 -= t;
	b2 -= t;
	if (a1 == 0) res1 = a1;
	if (a2 == 0) res2 = a2;
	else {
		res1 = a1 * powz(10, b1);
		res2 = a2 * powz(10, b2);
	}
	if (res1 != res2) {
		cout << ((res1 < res2) ? "X < Y" : "X > Y");
		return;
	}
	cout << "X = Y";
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