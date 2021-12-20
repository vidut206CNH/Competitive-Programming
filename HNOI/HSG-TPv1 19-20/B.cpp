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

ll cnt(ll n) {
	ll res = 0;
	while (n) {
		n /= 10;
		res++;
	}
	return res;
}

ll sol1(ll a, ll b, ll k) {
	ll i = 2;
	while ((a * powz(10, i) + b) % k || cnt((a * powz(10, i) + b) / k) != i - 1) {
		i++;
	}
	return (a * powz(10, i) + b) / k;
}

void solve() {
	ll a, b, k;
	cin >> a >> b >> k;
	k -= 10;
	cout << sol1(a, b, k);

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