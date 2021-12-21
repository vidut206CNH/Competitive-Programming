// link problem: https://codeforces.com/problemset/problem/1562/B
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
	int n, x;
	string s, tmp = "";
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		x = s[i] - '0';
		if (x != 2 && x != 3 && x != 5 && x != 7 ) {
			cout << 1 << '\n' << x;
			return;
		}
	}
	cout << 2 << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == '2' || s[j] == '5') {
				tmp += s[i];
				tmp += s[j];
				cout << tmp;
				return;
			}
			if (s[i] == s[j]) {
				tmp += s[i];
				tmp += s[j];
				cout << tmp;
				return;
			}
			if ((s[i] + s[j] - 2 * '0') % 3 == 0) {
				tmp += s[i];
				tmp += s[j];
				cout << tmp;
				return;
			}

		}
	}
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