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

void solve() {
	ll n, k, cnt = 0;
	string s;
	cin >> n >> k;
	map<ll, vector<ll> > a;
	set<ll> st;
	for (ll i = 1; i <= n; ++i) {
		cin >> s;
		a[s.size()].pb(i);
		st.insert(s.size());
	}
	for (auto x : st) {
		sort(a[x].begin(), a[x].end());
		ll i = 0;
		while (i < a[x].size()) {
			ll t = lower_bound(a[x].begin(), a[x].end(), a[x][i] + k) - a[x].begin();
			if (t == a[x].size() || a[x][t] > a[x][i] + k) --t;
			cnt += (t - i);
			i++;
		}
	}
	cout << cnt;
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