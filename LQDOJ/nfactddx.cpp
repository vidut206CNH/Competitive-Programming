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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
const ll MOD = 1000000007;
const ll nMax = 2e6 + 5;
bool chk[nMax + 1];

map<ll, ll> mp;
vector<ll> pri;

ll powz(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void sieve(ll n) {
	//memset(chk, 0, sizeof(chk));
	for (ll i = 2; i * i <= n; ++i) {
		if (!chk[i]) {
			for (ll j = i * i; j <= n; j += i) {
				chk[j] = 1;
			}
			pri.pb(i);
		}
	}
	for (ll i = sqrt(n) + 1; i <= n; ++i) {
		if (!chk[i]) {
			pri.pb(i);
		}
	}
	for (auto t : pri) {
		ll cnt = 0;
		int i = 1;
		while (n / powz(t, i) > 0) {
			cnt += n / powz(t, i);
			i++;
		}
		mp[t] = cnt;
	}
}

void solve() {
	ll n, x, ans = 1;
	cin >> n >> x;
	sieve(n);
	for (auto t : pri) {
		if (t * t > x) break;
		ll cnt = 0;
		while (x % t == 0) {
			cnt++;
			x /= t;
		}
		if (mp[t] < cnt) {
			cout << 0;
			return;
		}
		else mp[t] -= cnt;
	}
	if (x > 1) {
		if (mp.find(x) != mp.end()) mp[x]--;
		else {
			cout << 0;
			return;
		}
	}
	for (auto t : pri) {
		ans = (ans * (mp[t] + 1)) % MOD;
		//cout << mp[t] + 1 << ' ' << ans << '\n';
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