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

int bins(vector<ll> &a, int l, ll k) {
	int r = a.size() - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == k) return mid;
		if (a[mid] > k) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

void solve() {
	int n, t;
	cin >> n;
	vector<ll> a(n);
	set<ll> st;
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			ll tmp = (2 * a[j] - a[i]);
			int t = bins(a, j + 1, tmp);
			if (t) {
				st.insert(a[t]);
			}
		}
	}
	cout << st.size();
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