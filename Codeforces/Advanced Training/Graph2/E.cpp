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

int m,n;
vector<pii> adj[MAXN1];
int dp1[MAXN1];
int dp2[MAXN1];

int dp3[MAXN1];


void dfs1(int u, int par) {
	for(auto ed : adj[u]) {
		int v = ed.fi;
		if(v == par) continue;
		dfs1(v, u);
	}
	
	int id = 0;
	for(auto ed : adj[u]) {
		
		int v = ed.fi;
		int cost = ed.se;
		
		if(v == par) continue;
		
		if(dp1[u] < dp1[v] + cost) {
			dp1[u] = dp1[v] + cost;
			id = v;
		}
	}
	
	for(auto ed : adj[u]) {
		int v = ed.fi;
		int cost = ed.se;
		
		if(v == par) continue;
		
		if(id != v) {
			dp2[u] = max(dp2[u], dp1[v] + cost);
		}
	}
	
}

void dfs2(int u, int par) {
	for(auto ed : adj[u]) {
		
		int v = ed.fi;
		int cost = ed.se;
		
		if(v == par) continue;
		
		if(dp1[v] + cost == dp1[u]) dp3[v] = max(dp2[u], dp3[u]) + cost;
		else dp3[v] = max(dp1[u], dp3[u]) + cost;
		
		dfs2(v, u);
		
	}
}

signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	for(int u = 1; u <= n; ++u) {
		cout << dp1[u] + max(dp2[u], dp3[u]) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}