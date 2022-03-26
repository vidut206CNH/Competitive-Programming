/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 70003;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
vector<int> adj[MAXN1];
int up[MAXN1][18];
int st[4*MAXN1];
int h[MAXN1];

void dfs(int u) {
	for(auto v : adj[u]) {
		if(v == up[u][0]) continue;
		
		h[v] = h[u] + 1;
		up[v][0] = u;
		
		for(int i = 1; i < 18; ++i) {
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs(v);
	}
}


int lca(int u, int v) {
	if(u == -1 || v == -1) return (u + v + 1);
	if(h[u] < h[v]) swap(u,v);
	
	int diff = h[u] - h[v];
	
	for(int i = 0; (1 << i) <= diff; ++i) {
		if(diff >> i & 1) u = up[u][i];
	}
	
	if(u == v) return u;
	
	int step = log2(h[u]) + 1;
	
	while(step >= 0) {
		if(up[u][step] != up[v][step]) {
			u = up[u][step];
			v = up[v][step];
		}
		--step;
	}
	
	return up[u][0];
}

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	
	st[id] = lca(st[id << 1], st[id << 1|1]);
}


int get(int id, int l, int r, int u, int v) {
	if(r < u || v < l) return -1;
	if(u <= l && r <= v) {
		return st[id];
	}
	
	int mid = (l + r) >> 1;
	return lca(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}


signed main() {
	fast_cin();
	
	
	cin >> n >> q;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);
	
	build(1, 1, n);
	
	while(q--) {
		int l,r;
		cin >> l >> r;
		cout << get(1, 1, n, l, r) << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}