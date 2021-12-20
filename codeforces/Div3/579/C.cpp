// link problem: https://codeforces.com/contest/1203/problem/C
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

ll cnt(ll n) {
	ll res = 1, ct;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ct = 0;
			while (n % i == 0) {
				ct++;
				n /= i;
			}
			res *= (ct + 1);
		}
	}
	if (n > 1) res *= 2;
	return res;

}

void solve() {
	ll n, ans;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == 0) ans = a[i];
		ans = gcd(ans, a[i]);
	}
	cout << cnt(ans);
}


int main() {
	fast_cin();
	ll t = 1;
	//cin >> t;
	while (t) {
		solve();
		--t;
	}
	return 0;
}