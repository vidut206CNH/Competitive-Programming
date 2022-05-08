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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const long long inf = 1e18;

int n;
vector<int> adj[MAXN1];
int f[MAXN1];
int g[MAXN1];
int sf[MAXN1];
int sg[MAXN1];

int res = 0;

void dfs1(int u, int par) {
	vector<int> p;
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		dfs1(v, u);
		p.push_back(sf[v] + 1);
		sf[u] = max(sf[u], sf[v] + 1);
		f[u] = max(sf[v] + 1, f[u]);
		f[u] = max(f[v], f[u]);
		
	}
	
	sort(p.begin(), p.end(), greater<int>());
	
	if(sz(p) > 1) f[u] = max(f[u], p[0] + p[1]);
	
}


void dfs2(int u, int par) {
	
	
	g[u] = max(g[u], sg[u]);
	
	vector<pii> p,q;
	
	for(auto v : adj[u]) {
		
		if(v == par) continue;
		
		
		p.push_back({sf[v] + 1, v});
		q.push_back({f[v], v});
		
	}
	
	p.push_back({sg[u], u});
	q.push_back({g[u], u});
	
	sort(p.begin(), p.end(), greater<pii>());
	sort(q.begin(), q.end(), greater<pii>());
	
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		int cnt, sum;
		
		// p
		cnt = 0;
		sum = 0;
		
		for(int i = 0; i < min(sz(p), 3); ++i) {
			int val = p[i].fi;
			int t = p[i].se;
			
			if(t == v || cnt == 2) continue;
			cnt++;
			sum += val;
			sg[v] = max(sg[v], val + 1);
		}
		
		g[v] = max(sum, g[v]);
		
		
		
		// q
		
		
		for(int i = 0; i < min(sz(q), 2); ++i) {
			int val = q[i].fi;
			int t = q[i].se;
			if(t == v) continue;
			
			g[v] = max(g[v], val);
			
		}
		
	}
	
	
	
	for(auto v : adj[u]) {
		
		if(v == par) continue;
		
		int cnt = 0;
		int sum = 0;
		
		for(int i = 0; i < min(sz(p), 3); ++i) {
			
			int val = p[i].fi;
			int t = p[i].se;
			if(t == v || cnt == 2) continue;
			cnt++;
			sum += val;
			
		}
		
		
		res = max(res, max(sum, g[u])*f[v]);
		
		dfs2(v, u);
	}
	
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
	
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}