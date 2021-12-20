// link problem: https://codeforces.com/gym/331607/problem/2A
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
	ll n, k, cnt = 0, res = 1;
	cin >> n;
	k = n;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			res *= powz(i, cnt / 2);
		}
	}
	cout << res << ' ' << k / powz(res, 2) << '\n';
}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
	return 0;
}