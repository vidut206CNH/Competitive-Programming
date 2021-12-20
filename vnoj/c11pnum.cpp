/*
	link problem: https://oj.vnoi.info/problem/c11pnum
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
const ll nMax = 3e6 + 3;

ll a[11];
bool chk[nMax];
vector<ll> pri;
vector<ll> pref;


void sieve() {
	for (ll i = 2; i * i <= nMax; ++i) {
		if (!chk[i]) {
			for (ll j = i * i; j <= nMax; j += i) chk[j] = 1;
		}
	}
	for (ll i = 2; i <= nMax; ++i) {
		if (!chk[i]) pri.pb(i);
	}
}

void solve() {
	ll n, ans = 0;
	int k, pris = pri.size();
	cin >> n >> k;
	int t = lower_bound(pri.begin(), pri.end(), cbrt(n)) - pri.begin();
	if (t == pris) --t;
	while (t >= 0) {
		ll tmp = 1;
		int i = t, j = i;
		while (n / tmp >= pri[i] && i - j < min(k, pris - j)) {
			tmp *= pri[i];
			i++;
		}
		if (i - j == k && tmp <= n) {
			ans = max(ans, tmp);
		}
		--t;
	}
	if (!ans) cout << -1;
	else cout << ans;


}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	sieve();
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}