/*
	link problem:
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
	ll n = 0, b, k;
	cin >> n >> k >> b;
	b %= n;
	//if (b == 0) b = n;
	vector<ll> a(n + 1), pref(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	ll ans = k / n * pref[n];
	k %= n;
	k = (b + k - 1) % n;
	//if (k < 1) k = n;
	if (k < b) ans += pref[n] - pref[b - 1] + pref[k];
	else ans += pref[k] - pref[b - 1];
	cout << ans;

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