/*
	link problem: https://oj.vnoi.info/problem/nkrez
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
const ll nMax = 3e5 + 3;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.se < b.se);
}

int bins(int k, vector<pair<int, int> > &a) {
	int l = 0, r = a.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid].se == k) return mid;
		if (a[mid].se > k) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

void solve() {
	int n, ans = 0, maxx = 0;
	cin >> n;
	vector<pair<int, int> > p(n + 1);
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].fi >> p[i].se;
		a[i] = p[i].se;
		maxx = max(maxx, p[i].se);
	}
	sort(p.begin() + 1, p.end(), cmp);
	sort(a.begin(), a.end());
	vector<int> dp(maxx + 1, 0);
	for (int i = 1; i <= maxx; ++i) {
		dp[i] = dp[i - 1];
		int t = lower_bound(a.begin(), a.end(), i) - a.begin();
		if (a[t] == i) {
			while (a[t] == i) {
				dp[i] = max(dp[i], p[t].se - p[t].fi + dp[p[t].fi]);
				t++;
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans;

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