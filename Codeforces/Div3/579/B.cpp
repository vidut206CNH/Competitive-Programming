// link problem: https://codeforces.com/contest/1203/problem/C
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



void solve() {
	ll n, ans;
	cin >> n;
	vector<ll> a(4 * n);
	for (ll i = 0; i < 4 * n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int j = 0; j < 2 * n; j += 2) {
		int k = 4 * n - j - 1;
		if (j == 0) ans = a[j] * a[k];
		if (a[j] != a[j + 1] || a[k] != a[k - 1] || a[j]*a[k] != ans) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	while (t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}