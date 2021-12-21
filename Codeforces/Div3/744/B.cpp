/*
	link problem:
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

int lowb(int l, int r, int k, vector<int> &a) {
	int mid, ans = r;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] > k) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<int> > ans;
	int i = n - 1, j = i;
	while (j >= 0) {
		while (j >= 0 && a[j] >= a[j - 1]) j--;
		j--;
		if (j >= 0 && a[j] >= a[i]) {
			sort(a.begin() + j, a.begin() + i + 1);
			ans.pb({j + 1, i + 1, 1});
			//cout << i + 1 << ' ' << j + 1 << ' ' << 1 << '\n';
			j++;
		}
		else if (j >= 0 && a[j] < a[i]) {
			int t = lowb(j, i, a[j], a);
			--t;
			ans.pb({j + 1, t + 1, 1});
			//cout << t + 1 << ' ' << j + 1 << ' ' << 1 << '\n';
			sort(a.begin() + j, a.begin() + t + 1);
			j++;
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		for (auto t : x) {
			cout << t << ' ';
		}
		cout << '\n';
	}
}


int main() {
	fast_cin();
	ll t = 1;
	cin >> t;
	while (t) {
		solve();
		//	cout << '\n';
		--t;
	}
	return 0;
}