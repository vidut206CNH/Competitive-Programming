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

const int LOG = 20;
const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
vector<int> adj[MAXN1];
int h[MAXN1];
int p[MAXN1][LOG];
int dp[MAXN1];
int rem[MAXN1];
int res[MAXN1];



int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	
	for(int i = LOG - 1; i >= 0; --i) {
		if(h[u] - (1 << i) >= h[v]) {
			u = p[u][i];
		}
	}
	
	if(u == v) return u;
	
	for(int i = LOG - 1; i >= 0; --i) {
		if(p[u][i] != -1 && p[v][i] != -1 && p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	
	return p[u][0];
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> rem[i];
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// calc h[i], p[i][j]
	memset(h, -1, sizeof h);
	memset(p, -1, sizeof p);
	queue<int> qu;
	h[1] = 0;
	qu.push(1);
	
	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for(auto x : adj[u]) {
			if(h[x] != -1) continue;
			qu.push(x);
			p[x][0] = u;
			h[x] = h[u] + 1;
		}
	}
	
	for(int k = 1; k < LOG; ++k) {
		for(int i = 1; i <= n; ++i) {
			if(p[i][k - 1] != -1 && p[p[i][k - 1]][k - 1] != -1) {
				p[i][k] = p[p[i][k - 1]][k - 1];
			}
		}
	}
	
	int q;
	cin >> q;
	while(q--) {
		int u,v,val;
		cin >> u >> v >> val;
		dp[u] += val;
		dp[v] += val;
		dp[lca(u,v)] -= 2*val;
		rem[lca(u,v)] += val;
	}
	
	vector<pii > g;
	for(int i = 1; i <= n; ++i) {
		g.push_back({h[i], i});
	}
	
	sort(g.begin(), g.end(), greater<pii >());
	for(auto x : g) {
		int u = x.se;
		res[u] = dp[u] + rem[u];
		dp[p[u][0]] += dp[u];
	}
	

	
	for(int i = 1; i <= n; ++i) cout << res[i] << " ";
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}