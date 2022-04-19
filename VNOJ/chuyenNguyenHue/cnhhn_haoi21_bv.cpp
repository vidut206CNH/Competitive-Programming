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

int m,n,k;
vector<int> adj[MAXN1];
bool p[MAXN1];
int dp1[MAXN1];
int dp2[MAXN1];
int dp3[MAXN1];


void dfs1(int u, int par) {
	
	dp1[u] = (p[u] ? 0 : -1);
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		dfs1(v, u);
	}
	
	int id = 0;
	for(int v : adj[u]) {
		
		if(v == par) continue;
		
		if(dp1[v] != -1 && dp1[u] < dp1[v] + 1) {
			dp1[u] = dp1[v] + 1;
			id = v;
		}
	}
	
	for(int v : adj[u]) {
		
		if(v == par) continue;
		
		if(id != v && dp1[v] != -1) {
			
			dp2[u] = max(dp2[u], dp1[v] + 1);
			
		}
	}
	
}

void dfs2(int u, int par) {
	
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		if(dp3[v] == -1 && p[v]) {
			dp3[v] = 0;
		}
		
		dp3[v] = max(dp3[v], (dp3[u] != -1 ? dp3[u] : -2) + 1);
		
		if(dp1[u] != -1) {
			if(dp1[v] + 1 == dp1[u]) dp3[v] = max(dp3[v], dp2[u] + 1);
			else dp3[v] = max(dp3[v], dp1[u] + 1);
		}
		
		dfs2(v, u);
		
	}
}

signed main() {
	fast_cin();
	
	
	cin >> n >> m >> k;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		p[x] = true;
	}
	
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	memset(dp3, -1, sizeof dp3);
	
	dfs1(1, -1);
	
	dp3[1] = (p[1] ? 0 : -1);
	
	dfs2(1, -1);
	
	int res = 0;
	
	for(int i = 1; i <= n; ++i) {
/*		db(dp1[i]);
		db(dp3[i]);
		cerr << "\n";*/
		res += (max({dp1[i], dp3[i]}) <= k);
	}
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}