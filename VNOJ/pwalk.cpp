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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
vector<pii > adj[MAXN1];
int up[MAXN1][15];
int h[MAXN1];
int dist[MAXN1];

void dfs(int u) {
	for(auto x : adj[u]) {
		int v = x.fi;
		int w = x.se;
		if(v == up[u][0]) continue;
		
		h[v] = h[u] + 1;
		dist[v] = dist[u] + w;
		up[v][0] = u;
		for(int i = 1; i <= 10; ++i) {
			if(up[up[v][i - 1]][i - 1] == -1) break;
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs(v);
	}
}	


int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	
	int k = h[u] - h[v];
	for(int i = 0; (1 << i) <= k; ++i) {
		if((k >> i) & 1) {
			u = up[u][i];
		}
	}
	
	if(u == v) return u;	
	
	int lim = log2(h[u]);
	
	for(int i = lim; i >= 0; --i) {
		if(up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
}

void solve(int u, int v) {
	int p = lca(u,v);
	//db(p);
	cout << dist[u] + dist[v] - 2*dist[p] << "\n";
}


signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i < n; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	
	memset(h, -1, sizeof h);
	memset(up, -1, sizeof up);
	h[1] = 0;
	dfs(1);
	
	while(q--) {
		int u, v;
		cin >> u >> v;
		solve(u,v);
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}