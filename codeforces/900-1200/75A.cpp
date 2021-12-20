// link problem: https://codeforces.com/problemset/problem/75/A
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


string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() > b.size()) swap(a, b);
	int tmp, car = 0;
	string ans = "";
	for (int i = 0; i < a.size(); ++i) {
		tmp = a[i] + b[i] - 2 * '0' + car;
		ans = (char)(tmp % 10 + '0') + ans;
		car = tmp / 10;
	}
	for (int i = a.size(); i < b.size(); ++i) {
		tmp = b[i] - '0' + car;
		ans = (char)(tmp % 10 + '0') + ans;
		car = tmp / 10;
	}
	if (car) ans = '1' + ans;
	return ans;
}

void solve() {
	string a, b, s, s1 = "", a1 = "", b1 = "";
	cin >> a >> b;
	s = add(a, b);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '0') s1 += s[i];
	}
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != '0') a1 += a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		if (b[i] != '0') b1 += b[i];
	}
	cout << ((add(a1, b1) == s1) ? "YES" : "NO") << '\n';
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