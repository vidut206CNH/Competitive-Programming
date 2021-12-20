// link problem: https://codeforces.com/contest/1203/problem/A
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
// dp O(n^2) - fail
// void solve() {
// 	int n, ans = 0, temp;
// 	cin >> n;
// 	vector<int> a(n), dp(n);
// 	for (int i = 0; i < n; ++i) {
// 		cin >> a[i];
// 		dp[i] = 1;
// 	}
// 	sort(a.begin(), a.end());
// 	for (int i = 1; i < n; ++i) {
// 		temp = 0;
// 		for (int j = i - 1; j >= 0; --j) {
// 			if (a[i] % a[j] == 0) {
// 				temp = max(temp, dp[j]);
// 			}
// 		}
// 		dp[i] += temp;
// 		ans = max(ans, dp[i]);
// 	}
// 	cout << n - ans;
// }
void solve() {
	int x, ans = 0, temp, n;
	cin >> n;
	vector<int> a(nMax, 0), cnt(nMax, 0);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1e6; i > 0; i--) {
		temp = 0;
		for (int j = 2 * i; j <= 1e6; j += i) temp = max(temp, cnt[j]);
		cnt[i] += temp;
		ans = max(cnt[i], ans);
	}
	cout << n - ans;
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