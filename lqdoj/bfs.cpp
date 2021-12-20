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
vector<int> adj[nMax + 1];
vector<int> cost(nMax + 1, 0);
queue<int> q;
void BFS(int s) {
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto x : adj[u]) {
			if (!cost[x] && x != s)  {
				cost[x] = cost[u] + 1;
				q.push(x);
			}
		}
	}
}
void solve() {
	int n, m, u, v, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	BFS(s);
	vector<p32> p;
	for (int i = 1; i <= n; ++i) {
		if (cost[i] || i == s) {
			p.pb({cost[i], i});
		}
	}
	sort(p.begin(), p.end());
	for (auto x : p) {
		cout << x.se << ' ' << x.fi << '\n';
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