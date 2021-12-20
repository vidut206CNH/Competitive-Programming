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
const ll nMax = 1e5 + 3;

ll a[nMax + 1], pref[nMax + 1];


void sol1() {
	a[0] = 0;
	a[1] = 1;
	pref[1] = 1;
	for (ll i = 2; i <= nMax; ++i) {
		if (i % 2) a[i] = a[i / 2] + a[i / 2 + 1];
		else a[i] = a[i / 2];
		pref[i] = max(pref[i - 1], a[i]);
	}
}

void solve() {
	ll n;
	cin >> n;
	cout << pref[n];
}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	sol1();
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}