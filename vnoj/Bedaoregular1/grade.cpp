/*
	link problem:
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const ll nMax = 1e6 + 3;

void solve() {
	int n, x, y, q;
	cin >> n >> q;
	vector < vector<int> > dp(nMax, vector<int>(3, 0));
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		for (int j = 0; j < x; ++j) {
			cin >> y;
			if (dp[y][2] == i - 1) dp[y][1]++;
			else if (dp[y][2] != i) dp[y][1] = 1;
			dp[y][0] = max(dp[y][0], dp[y][1]);
			dp[y][2] = i;
		}
	}
	for (int i = 0; i < q; ++i) {
		cin >> x;
		cout << dp[x][0] << '\n';
	}
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