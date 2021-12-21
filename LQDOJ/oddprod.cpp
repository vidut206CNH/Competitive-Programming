/*
	link problem: https://lqdoj.edu.vn/problem/oddprod
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
	int n, res = 0;
	cin >> n;
	vector<int> a(n + 1), pref(n + 1, 0);
	vector<int> chk(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		chk[i] = chk[i - 1] + (a[i] % 2 == 0);
		pref[i] = pref[i - 1] + (a[i] < 0);
		if (pref[i] % 2 == 0 && chk[i]) {
			res = max(res, i);
		}
	}
	int i = 2;
	while (i + res - 1 <= n) {
		for (int j = i + res - 1; j <= n; ++j) {
			if ((pref[j] - pref[i - 1]) % 2 == 0 && chk[j] - chk[i - 1]) {
				res = max(res, j - i + 1);
			}
		}
		i++;
	}
	cout << res;

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