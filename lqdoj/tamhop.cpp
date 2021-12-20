// link problem: https://lqdoj.edu.vn/problem/tamhop
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

bool bins(int k, vector<int> &a) {
	int st = 0, ed = a.size() - 1, mid;
	while (st <= ed) {
		mid = (st + ed) / 2;
		if (a[mid] == k) return 1;
		if (a[mid] < k) st = mid + 1;
		else ed = mid - 1;
	}
	return 0;
}

void solve() {
	int n, ans = -1e6 - 1, cnt = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 2; j < n; ++j) {
			if ((a[i] + a[j]) % 2 == 0 && bins((a[i] + a[j]) / 2, a)) {
				cnt++;
				ans = max(ans, (a[i] + a[j]) / 2);
			}
		}
	}
	if (cnt) cout << cnt << '\n' << ans * 3;
	else cout << 0 << '\n' << 0;
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