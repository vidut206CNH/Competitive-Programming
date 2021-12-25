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

int lowb(const vector<int> m[], int t, int k) {
	int l = 0, r = m[t].size() - 1, mid, ans = r + 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (m[t][mid] == k) return mid;
		if (m[t][mid] > k) {
			r = mid - 1;
			ans = min(ans, mid);
		}
		else l = mid + 1;
	}
	return ans;
}

void solve() {
	int n, t;
	cin >> n;
	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	vector<int> m[3];
	map<ll, int> mp;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		t = a[i] % 3;
		mp[a[i]] = 1;
		if (t < 0) t = 3 + t;
		m[t].pb(i);
	}
	set<ll> st;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 2; j < n; ++j) {
			t = (6 - a[i] % 3 - a[j] % 3) % 3;
			//cout << t << '\n';
			int it = lowb(m, t, i + 1);
			while (it < m[t].size() && m[t][it] < j) {
				ll tmp = (a[m[t][it]] + a[i] + a[j]) / 3;
				if (mp.find(tmp) != mp.end()) {
					//cout << a[i] << ' ' << a[m[t][it]] << ' ' << a[j] << '\n';
					st.insert(tmp);
				}
				it++;
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