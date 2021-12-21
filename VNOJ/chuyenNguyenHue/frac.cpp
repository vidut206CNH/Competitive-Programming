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

map<ll, ll> ma, maxx;
set<ll> pri;
ll cnt = 0;

void factor(ll x) {
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			cnt = 0;
			while (x % i == 0) {
				x /= i;
				cnt++;
			}
			if (ma.find(i) != ma.end()) {
				if (maxx[i] <= cnt) maxx[i] = cnt;
				ma[i] += cnt;
			}
			else {
				maxx[i] = cnt;
				ma[i] = cnt;
			}
			pri.insert(i);
		}

	}
	if (x > 1) {
		if (ma.find(x) != ma.end()) {
			ma[x] += 1;
		}
		else {
			maxx[x] = 1;
			ma[x] = 1;
		}
		pri.insert(x);
	}
}

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
	int n;
	cin >> n;
	if (n == 0) {
		cout << "impossible";
		return;
	}
	ll x, ans = 1;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x == 0) {
			cout << "impossible";
			return;
		}
		factor(x);
	}
	for (auto t : pri) {
		ans *= powz(t, ma[t] - maxx[t]);
		//cout << ma[t] << ' ' << maxx[t];
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