#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll;
typedef pair<int, int> pii;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<vector<int>> e, kids;
vector<int> d, q, p;
bool viv = false;

void DFS(int v, int my_d = 0) {
	d[v] = my_d;
	for (auto u : e[v])
		if (d[u] == -1) {
			DFS(u, my_d + 1);
			p[u] = v;
			kids[v].push_back(u);
		}
	q.push_back(v);
}

vector<int> st0, st1, st2;
vector<int> dp0, dp1, dp2;

void work(int v) {
	sort(kids[v].begin(), kids[v].end(), [&](int a, int b) {
				return st2[a] > st2[b];
			}
		);

	int best_k = 0;
	for (int i = 0; i < min(k - 0, (int)kids[v].size()); i++)
		best_k += st2[kids[v][i]] + 2;
	int best_km = 0;
	for (int i = 0; i < min(k - 1, (int)kids[v].size()); i++)
		best_km += st2[kids[v][i]] + 2;
	int best_kmm = 0;
	for (int i = 0; i < min(k - 2, (int)kids[v].size()); i++)
		best_kmm += st2[kids[v][i]] + 2;

	int kids_st2_k = -2;
	int kids_st2_km = -2;
	int kids_st2_kmm = -2;
	if (kids[v].size() >= k + 1)
		kids_st2_k = st2[kids[v][k]];
	if (kids[v].size() >= k)
		kids_st2_km = st2[kids[v][k - 1]];
	if (kids[v].size() >= k - 1 && k >= 2)
		kids_st2_kmm = st2[kids[v][k - 2]];

	st2[v] = best_km;
	// st0[v] = best_k;
	// if (kids[v].size() >= k)
	// 	st0[v]--;

	st1[v] = st2[v];
	for (int i = 0; i < kids[v].size(); i++) {
		int u = kids[v][i];
		int lose = st2[u] - min(st2[u], kids_st2_km);
		st1[v] = max(st1[v], st2[v] - lose + (st1[u] + 1));
	}
	st0[v] = max(st0[v], st1[v]);

	dp2[v] = st2[v];
	dp1[v] = st1[v];
	dp0[v] = st0[v];

	if (k >= 2) {
		for (int i = 0; i < kids[v].size(); i++) {
			int u = kids[v][i];
			int lose = 2 + max(st2[u], kids_st2_kmm);
			dp2[v] = max(dp2[v], best_km - lose + (dp2[u] + 2));
		}

		vector<int> line0(kids[v].size() + 1, best_kmm);
		vector<int> line1(kids[v].size() + 1, best_kmm);
		vector<int> line2(kids[v].size() + 1, best_kmm);
		for (int i = 0; i < kids[v].size(); i++) {
			int u = kids[v][i];
			int add = st1[u] + 1;
			int lose = st2[u] - min(st2[u], kids_st2_kmm);
			line1[i + 1] = max(line1[i], line0[i] - lose + add);
		}
		for (int i = 0; i < kids[v].size(); i++) {
			int u = kids[v][i];
			int add = st1[u] + 1;
			int lose = st2[u] - min(st2[u], kids_st2_km);
			line2[i + 1] = max(line2[i], line1[i] - lose + add);
		}
		for (auto val : line2)
			dp2[v] = max(dp2[v], val);
		for (auto val : line1)
			dp2[v] = max(dp2[v], val);
	}
	if (k >= 1) {
		for (int i = 0; i < kids[v].size(); i++) {
			int u = kids[v][i];
			int lose = 2 + max(st2[u], kids_st2_km);
			if (k >= 2)
				dp0[v] = max(dp0[v], best_k - lose + (dp2[u] + 2));
		}

		vector<int> line0(kids[v].size() + 1, best_km);
		vector<int> line1(kids[v].size() + 1, best_km);
		vector<int> line2(kids[v].size() + 1, best_km);
		for (int i = 0; i < kids[v].size(); i++) {
			int u = kids[v][i];
			int add = st1[u] + 1;
			int lose = st2[u] - min(st2[u], kids_st2_km);
			line1[i + 1] = max(line1[i], line0[i] - lose + add);
		}
		for (int i = 0; i < kids[v].size(); i++) {
			int u = kids[v][i];
			int add = st1[u] + 1;
			int lose = st2[u] - min(st2[u], kids_st2_k);
			line2[i + 1] = max(line2[i], line1[i] - lose + add);
		}
		for (auto val : line1)
			dp1[v] = max(dp1[v], val);
		for (auto val : line2)
			dp0[v] = max(dp0[v], val);
	}
	dp0[v] = max(dp0[v], dp1[v]);
	if (viv) {
		cout << "\t\t\tst = " << st2[v] << ", " << st1[v] << ", " << st0[v] << "\n";
		cout << "\t\t\tdp = " << dp2[v] << ", " << dp1[v] << ", " << dp0[v] << "\n";
	}
}

void work_all() {
	st2.assign(n, 0);
	st1.assign(n, 0);
	st0.assign(n, 0);

	dp2.assign(n, 0);
	dp1.assign(n, 0);
	dp0.assign(n, 0);

	for (auto v : q)
		work(v);
}

int solve_rooted(int root) {
	d.assign(n, -1);
	p.assign(n, -1);
	q.clear();
	kids.assign(n, {});
	DFS(root);
	work_all();

	int res = 0;
	for (auto i : dp0)
		res = max(res, i);
	return res;
}

void solve() {
	cin >> n >> k;
	e.assign(n, {});
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int answer = solve_rooted(0);
	cout << answer << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("tkb.inp", "r", stdin);
   freopen("tkb.out", "w", stdout);
	ll t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
