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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,m;
vector<int> adj[MAXN1];
int g[MAXN1];
int a[MAXN1];
bool ok[MAXN1];
bool vis[MAXN1];

void dfs(int u) {
	
	g[u] = sz(adj[u]);
	vis[u] = true;	
	
	for(int v : adj[u]) {
		if(!vis[v]) dfs(v);	
	}
	
	for(int v : adj[u]) {
		if(g[v] < sz(adj[u])) ok[g[v]] = true;
	}
	
	for(int i = 0; i < sz(adj[u]); ++i) {
		if(!ok[i]) {
			g[u] = min(g[u], i);
		}
		ok[i] = false;
	}
}

int main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) dfs(i);
	}
	
	int nim = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i]&1) nim ^= g[i];
	}
	
	cout << (nim ?  "YES\n" : "NO\n");
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}