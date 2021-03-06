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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
vector<int> adj[MAXN1];
vector<int> f(MAXN1,0),g(MAXN1, 0),d(MAXN1, 0);


void dfs1(int cur=1, int par = 0) {
	d[cur] = 1;
	for(auto x : adj[cur]) {
		if(x == par) continue;
		dfs1(x, cur);
		f[cur] += (f[x] + d[x]);
		d[cur] += d[x];
	}	
	
	
}


void dfs2(int cur = 1, int par =  0) {
	if(cur != 1) {
		g[cur] = (f[par] - (d[cur] + f[cur]) + (d[par] - d[cur])) + (n - d[par] + g[par]);
	}
	
	for(auto x : adj[cur]) {
		if(x == par) continue;
		dfs2(x, cur);
	}
	
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<n;++i) {
		int u,v;
		
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}	
	
	dfs1();
	dfs2();
	
	for(int i=1;i<=n;++i) {
/*		db(f[i]);
		db(g[i]);
		cerr << "\n";*/
		cout << g[i] + f[i] << " ";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}