// link problem: https://codeforces.com/problemset/problem/894/a
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
	int cnt = 0;
	string s;
	cin >> s;
	int  n = s.size();
	vector<int> pref(n + 2, 0), suf(n + 2, 0);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i];
		if (s[i] == 'Q') pref[i + 1]++;
	}
	for (int i = n - 1; i >= 0; --i) {
		suf[i + 1] = suf[i + 2];
		if (s[i] == 'Q') suf[i + 1]++;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'A') {
			cnt += (pref[i] * suf[i + 2]);
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