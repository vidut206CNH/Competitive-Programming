/* 
	link problem: 
	Author : vidut_206_CNH
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

void solve() {
	int m, n, l, r, x;
	cin >> m >> n;
	vector< pii > p(m);
	for (int i = 0; i < m; ++i) {
		cin >> p[i].fi;
		p[i].se = 0;
	}
	//sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < n; ++i) {
		cin >> l >> r >> x;
		for (auto &t : p) {
			if (l <= t.fi && t.fi <= r) {
				t.se += (((t.fi - l) % 2 == 0) ? x : -x);
			}
		}
	}
	for (auto t : p) {
		cout << t.se << '\n';
	}
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}