/*
	link problem:
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
#include <math.h>
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
#define _USE_MATH_DEFINES

const ll MOD = 1000000007;
const ll nMax = 1e6 + 1;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
double alpha(const double &a, const double &b, const double &c) {
	return acos((a * a + b * b - c * c) / (2 * a * b));
}

void solve() {
	int n;
	cin >> n;
	double a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	double l = 0, h = 1e9, r;
	while (h - l > eps) {
		r = (l + h) / 2;
		double tmp = alpha(r + a[0], r + a[n - 1], a[0] + a[n - 1]);
		for (int i = 1; i < n; ++i) {
			tmp += alpha(r + a[i], r + a[i - 1], a[i] + a[i - 1]);
		}
		if (tmp > 2 * PI) l = r;
		else h = r;
	}
	cout << fixed << setprecision(3) << (l + h) / 2;
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