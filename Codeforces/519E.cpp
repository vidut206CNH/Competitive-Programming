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

int n;
vector<int> adj[MAXN1];
int h[MAXN1];
int dp[MAXN1];
int up[MAXN1][20];

void dfs(int u) {
	dp[u] = 1;
	for(auto v : adj[u]) {
		if(v == up[u][0]) continue;
		h[v] = h[u] + 1;
		up[v][0] = u;
		
		for(int i = 1; i < 20; ++i) {
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs(v);
		dp[u] += dp[v];
	}
}


int lca(int u, int v) {
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
		step--;
	}
	
	return up[u][0];
}

int ancesstor_k(int x, int k) {
	
	for(int i = 0; (1 << i) <= k; ++i) {
		if(k >> i & 1) x = up[x][i];
	}
	
	return x;
}

int dist(int u, int v) {
	int p = lca(u,v);
	return h[u] + h[v] - 2*h[p];
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);
	
	int q;
	cin >> q;
	while(q--) {
		int u,v;
		cin >> u >> v;
		int l = dist(u,v);
		if(l&1) {
			cout << "0\n";
		}
		else {
			int p = lca(u,v);
			if(h[u] == h[v]) {
				if(u == v) {
					cout << n << "\n";
					continue;
				}
				int u1 = ancesstor_k(u, h[u] - (h[p] + 1));
				int v1 = ancesstor_k(v, h[v] - (h[p] + 1));
				cout << n - dp[u1] - dp[v1] << "\n";
			}
			else {
				if(h[u] > h[v]) swap(u,v);
				int g = ancesstor_k(v, l/2);
				int v1 = ancesstor_k(v, l/2 - 1);
				db(g);
				cerr << '\n';
				cout << dp[g] - dp[v1] << "\n";
			}
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}