/*
	link problem: https://oj.vnoi.info/problem/bones
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
const ll nMax = 1e5 + 1;

int cnt[nMax];

void solve() {
	vector<int> a(4, 0);
	int sum = 0, ans = 0, id;
	for (int i = 1; i <= 3; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	vector< vector<int> > dp(4, vector<int>(sum + 1, 0));
	for (int i = 1; i <= a[1]; ++i) dp[1][i] = 1;
	for (int i = 2; i <= 3; ++i) {
		for (int j = sum; j >= i; --j) {
			for (int l = 1; l <= min(a[i], j - i + 1); ++l) {
				dp[i][j] += dp[i - 1][j - l];
			}
		}
	}
	for (int i = 3; i <= sum; ++i) {
		if (dp[3][i] > ans) {
			ans = dp[3][i];
			id = i;
		}
	}
	cout << id;
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