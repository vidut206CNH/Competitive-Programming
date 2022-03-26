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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
vector<pii > adj[MAXN1];
int h[MAXN1];


int mi[MAXN1][20];
int ma[MAXN1][20];
int up[MAXN1][20];

void dfs(int u) {
	for(auto x : adj[u]) {
		int v = x.fi;
		int w = x.se;
		if(v == up[u][0]) continue;
		h[v] = h[u] + 1;
		
		up[v][0] = u;
		mi[v][0] = w;
		ma[v][0] = w;
		
		for(int i = 1; i < 20; ++i) {
			up[v][i] = up[up[v][i - 1]][i - 1];
			mi[v][i] = min(mi[v][i - 1], mi[up[v][i - 1]][i - 1]);
			ma[v][i] = max(ma[v][i - 1], ma[up[v][i - 1]][i - 1]);
		}
		
		dfs(v);
	}
}


int lca(int u, int v) {
	
	if(h[u] < h[v]) swap(u,v);
	
	int diff = h[u] - h[v];
	
	for(int i = 0; (1 << i) <= diff; ++i) {
		if(diff >> i & 1) {
			u = up[u][i];		
		}
	}
	
	if(u == v) return u;
	
	int step = log2(h[u]) + 2;
	
	while(step >= 0) {
		if(up[u][step] != up[v][step]) {
			u = up[u][step];
			v = up[v][step];
		}
		--step;
	}
	
	return up[u][0];
	
}


void solve(int u, int v) {
	int res_min = inf, res_max = 0;
	
	int p = lca(u, v);
	int diff1 = h[u] - h[p];
	int diff2 = h[v] - h[p];
	for(int i = 0; (1 << i) <= diff1; ++i) {
		if(diff1 >> i & 1) {
			res_min = min(res_min, mi[u][i]);
			res_max = max(res_max, ma[u][i]);
			u = up[u][i];
		}
	}
	
	for(int i = 0; (1 << i) <= diff2; ++i) {
		if(diff2 >> i & 1) {
			res_min = min(res_min, mi[v][i]);
			res_max = max(res_max, ma[v][i]);
			v = up[v][i];
		}
	}
	
	cout << res_min << " " << res_max << "\n";
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	
	memset(mi, 0x3f, sizeof mi);
	dfs(1);
	cin >> q;
	while(q--) {
		int u,v;
		cin >> u >> v;
		solve(u,v);
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}