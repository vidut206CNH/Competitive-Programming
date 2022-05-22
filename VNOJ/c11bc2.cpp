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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;

vector<pii> adj[MAXN1];
int up[MAXN1][17];
bool ok[MAXN1][17];
int h[MAXN1];

void dfs(int u, int par) {
	for(auto x : adj[u]) {
		int v = x.fi;
		int k = x.se;
		if(v == par) continue;
		
		up[v][0] = u;
		ok[v][0] = (k == 2);
		h[v] = h[u] + 1;
		
		for(int i = 1; i <= 15; ++i) {
			up[v][i] = up[up[v][i - 1]][i - 1];
			ok[v][i] = (ok[v][i - 1] || ok[up[v][i - 1]][i - 1]);
		}
		
		dfs(v, u);
	}
}


bool check(int u, int v) {
	
	bool res = false;
	if(h[u] < h[v]) swap(u, v);
	
	int diff = h[u] - h[v];
	for(int i = 0; (1 << i) <= diff; ++i) {
		if(diff >> i & 1) {
			res |= (ok[u][i]);
			u = up[u][i];
		}
	}
	
	if(u == v) return res;
	
	for(int i = 15; i >= 0; --i) {
		if(up[u][i] != up[v][i]) {
			res |= (ok[u][i]);
			res |= (ok[v][i]);
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	res |= (ok[u][0]);
	res |= (ok[v][0]);
	
	return res;
}





signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int u = 2; u <= n; ++u) {
		int v,k;
		cin >> v >> k;
		adj[u].push_back({v, k});
		adj[v].push_back({u, k});
	}
	
	
	dfs(1, -1);
	
	while(m--) {
		int u,v;
		cin >> u >> v;
		cout << (check(u, v) ? "YES\n" : "NO\n");
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}