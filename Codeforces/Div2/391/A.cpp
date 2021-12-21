// link problem: https://codeforces.com/contest/757/problem/A
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
vector<int> a(260, 0);
int ans = MOD;
char c;

void solve() {
	while (cin >> c) {
		a[c]++;
	}
	ans = min(ans, a['B']);
	ans = min(ans, a['a'] / 2);
	ans = min(ans, a['b'] / 2);
	ans = min(ans, a['l']);
	ans = min(ans, a['s']);
	ans = min(ans, a['r']);
	ans = min(ans, a['u'] / 2);
	ans = min(ans, a['s']);
	cout << ans;
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