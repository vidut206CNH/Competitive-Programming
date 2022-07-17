/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 1e6+5;
const int MAXN2 = 4e6+5;

struct rec{
	int x,y,u,v;
};

int n,m;
rec a[MAXN1];
vector<int> queries[MAXN1];
vector<int> adj[MAXN1];
pii que[MAXN1];



int h[MAXN1];
int up[MAXN1][25];


void dfs(int u) {
	
	for(int v : adj[u]) {
		if(v == up[u][0]) continue;
		
		h[v] = h[u] + 1;
		up[v][0] = u;
		for(int i = 1; i <= 20; ++i) {
			
			if(up[v][i - 1] == -1) break;
			
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs(v);
	}
	
}


int lca(int u, int v) {
	
	if(h[u] < h[v]) swap(u,v);
	int diff = h[u] - h[v];
	for(int i = 0; i <= 20; ++i) {
		if(diff >> i & 1) u = up[u][i];
	}
	
	if(u == v) return u;
	
	for(int i = 20; i >= 0; --i) {
		if(up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
	
}

int dist(int u, int v) {
	return h[u] + h[v] - 2*h[lca(u, v)];
}

int ff(int X, int Y, int U, int V, int id) {
	
	int best = 2e9 + 7, node_v = 0;
	
	for(int j = 1; j <= n; ++j) {
		if(a[j].x >= X || a[j].y >= Y) continue;
		if(a[j].u <= U || a[j].v <= V) continue;
		if(id == j) continue;
		
		int diff = min({X - a[j].x, Y - a[j].y, a[j].u - U, a[j].v - V});
		if(diff < best) {
			best = diff;
			node_v = j;
		}
	}
	
	return node_v;
	
}

int main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		
		cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v;
		
	}
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < 4; ++j) {
			int x;
			cin >> x;
			queries[i].push_back(x);
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		
		int X = a[i].x;
		int Y = a[i].y;
		int U = a[i].u;
		int V = a[i].v;
		
		int node = ff(X, Y, U, V, i);
		
		adj[node].push_back(i);
		adj[i].push_back(node);
	}
	
	for(int i = 1; i <= m; ++i) {
		
		
		//
		
		
		int X,Y, U, V;
		X = U =  queries[i][0]; Y = V = queries[i][1];
		int node = ff(X, Y, U, V, -1);
		que[i].fi = node;
		
		
		//
		
		X = U = queries[i][2]; Y = V = queries[i][3];
		node = ff(X, Y, U, V, -1);
		que[i].se = node;
		
	}
	
	// LCA
	
	memset(up, -1, sizeof up);
	dfs(0);
	
	
	
	// answer
	for(int i = 1; i <= m; ++i) {
		cout << dist(que[i].fi, que[i].se) << "\n";
	}
	
	
	// sub1 + sub2 -  O(n^2)
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}