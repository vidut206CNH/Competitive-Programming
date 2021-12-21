/*
	link problem: https://oj.vnoi.info/problem/baricavn
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
const int nMax1 = 1e5 + 5;

int bins(vector< pair< ll, pair<ll, ll> > > &p, pair<ll, p64> &a) {
	int l = 0, r = p.size() - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (p[mid] == a) return mid;
		if (p[mid].fi == a.fi) {
			if (p[mid].se. fi < a.se. fi) l = mid + 1;
			else r = mid - 1;
		}
		else if (p[mid].fi > a.fi) r = mid - 1;
		else l = mid + 1;
	}
	return r + 1;
}


void solve() {
	int n, k, x, y, f, idx, idy;
	cin >> n >> k;

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