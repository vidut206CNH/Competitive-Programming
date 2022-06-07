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

typedef pair<long long,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n, k;
vector<int> adj[MAXN1];
long long down[2][MAXN1];
long long up[2][MAXN1];
long long dp[2][MAXN1];


void dfs1(int u, int par) {
	
	vector<pii> p;
	for(int v : adj[u]) {
		if(v == par) continue;
		dfs1(v, u);
		p.push_back({down[0][v] + 2, v});
	}
	
	sort(p.begin(), p.end(), greater<pii>());
	
	for(int i = 0; i < min(sz(p), k - 1); ++i) {
		long long val = p[i].fi;
		down[0][u] += val; 
	}
	
	if(sz(p) > k - 1) {
		long long sum = down[0][u] + p[k - 1].fi;
		for(int i = 0; i <= k - 1; ++i) {
			down[1][u] = max(down[1][u], sum - p[i].fi + down[1][p[i].se] + 1);
		}
		for(int i = k; i < sz(p); ++i) {
			down[1][u] = max(down[1][u], sum - p[k - 1].fi + down[1][p[i].se] + 1);
		}
	}
	
	else {
		long long sum = down[0][u];
		for(int i = 0; i < min(sz(p), k - 1); ++i) {
			down[1][u] = max(down[1][u], sum - p[i].fi + down[1][p[i].se] + 1);
		}
		
	}
	
}



void dfs2(int u, int par) {
	
	
	// calc res
	vector<pii> p;
	vector<pii> g;
	for(int v : adj[u]) {
		if(v == par) continue;
		p.push_back({down[0][v] + 2, v});
	}
	
	p.push_back({up[0][u], u});
	
	sort(p.begin(), p.end(), greater<pii>());
	
	for(int i = 0; i < min(sz(p), k - 1); ++i) {
		long long val = p[i].fi;
		int v = p[i].se;
		dp[0][u] += val;
	}
	
	
	if(sz(p) > k - 1) {
		// calc up[0][v]
		for(int i = 0; i < k - 1; ++i) {
			long long val = p[i].fi;
			int v = p[i].se;
			if(v == u) continue;
			up[0][v] = dp[0][u] - val + 2;
		}
		
		for(int i = k - 1; i < sz(p); ++i) {
			long long val = p[i].fi;
			int v = p[i].se;
			if(v == u) continue;
			up[0][v] = dp[0][u] - p[k - 2].fi + 2;
			
		}
		
		// calc dp[1][u]
		long long sum = dp[0][u] + p[k - 1].fi;
		
		for(int i = 0; i <= k - 1; ++i) {
			long long val = sum - p[i].fi + (p[i].se == u ? up[1][u] : down[1][p[i].se] + 1);
			int v = p[i].se;
			dp[1][u] = max(dp[1][u], val);
			
			if(i == k - 1) {
				g.push_back({val, v});
			}
			
			else {
				g.push_back({val, v});
			}
		}
		for(int i = k; i < sz(p); ++i) {
			long long val = sum - p[k - 1].fi + (p[i].se == u ? up[1][u] : down[1][p[i].se] + 1);
			int v = p[i].se;
			dp[1][u] = max(dp[1][u], val);
			
			g.push_back({val, v});
		}
		
		sort(g.begin(), g.end(), greater<pii>());
		
		
		for(int i = 0; i < k - 2; ++i) {
			long long val = p[i].fi;
			int v = p[i].se;
			if(v == u) continue;
			
			up[1][v] = ((v == g[0].se ? g[1].se : g[0].se) - val + 1);
		}
		
		for(int i = k - 2; i < sz(p); ++i) {
			long long val = p[i].fi;
			int v = p[i].se;
			if(v == u) continue;
			if(v == g[0].se) {
				up[1][v] = g[1].se - val + 1;
				
			}
		}
		
		
	}
	
	else {
		long long sum = dp[0][u];
		for(int i = 0; i < min(sz(p), k - 1); ++i) {
			long long val = sum - p[i].fi + (p[i].se == u ? up[1][u] : down[1][p[i].se] + 1);
			int v = p[i].se;
			dp[1][u] = max(dp[1][u], val);
			g.push_back({val, v});
		}
		
	}
	
	
	// change root to children
	
	for(int v : adj[u]) {
		if(v == par) continue;
		dfs2(v, u);
	}
	
	
}

int cnt[MAXN1];

void dfs3(int u, int par) {
	for(int v : adj[u]) {
		if(v == par) continue;
		cnt[v] = cnt[u] + 1;
		dfs3(v, u);
	}
}



int main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	if(k == 1) {
		dfs3(1, -1);
		int root = 0, best = 0;
		for(int i = 1; i <= n; ++i) {
			if(best < cnt[i]) {
				best = cnt[i];
				root = i;
			}
		}
		
		cnt[root] = 0;
		dfs3(root, -1);
		for(int i = 1; i <= n; ++i) {
			best = max(best, cnt[i]);
		}
		
		cout << best << "\n";
		exit(0);
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	long long res = 0;
	for(int i = 1; i <= n; ++i) {
		db(dp[0][i]);
		db(dp[1][i]);
		cerr << "\n";
		res = max({res, dp[0][i], dp[1][i]});
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}