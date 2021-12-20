/*
	link problem: https://oj.vnoi.info/problem/dhbb21_easytask
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
const ll nMax = 1e6 + 3;
bool chk[nMax];
vector<int> pri;

void sieve() {
	chk[1] = 1;
	chk[0] = 1;
	for (int i = 2; i * i <= nMax; ++i) {
		if (!chk[i]) {
			for (int j = i * i; j <= nMax; j += i) chk[j] = 1;
		}
	}
	for (int i = 2; i <= nMax; ++i) {
		if (!chk[i]) pri.pb(i);
	}
}

void solve() {
	sieve();
	ll n, ans = -nMax;
	cin >> n;
	vector<ll> a(n + 1), pref(n + 1, 0), minn(n + 1, nMax);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		if (!chk[i]) minn[i] = min(minn[i - 1], pref[i - 1]);
		else minn[i] = minn[i - 1];
	}
	for (auto x : pri) {
		if (x > n) break;
		ans = max(ans, pref[x] - minn[x]);
		//cout << pref[x] << ' ' << minn[x]  << ' ' << x << '\n';
	}
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