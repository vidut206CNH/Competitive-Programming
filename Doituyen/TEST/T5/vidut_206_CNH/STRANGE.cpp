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

int n,k;
vector<int> adj[MAXN1];
int dp[2][MAXN1];
bool f[MAXN1];

void dfs1(int u, int par) {
	for(auto v : adj[u]) {
		if(v == par) continue;
		dfs1(v, u);
		f[u] |= f[v];
	}
}

void dfs2(int u, int par) {
	vector<pii> p;
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		dfs2(v, u);
		
		if(f[v]) {
			p.push_back({dp[0][v], dp[1][v]});
		}
	}
	
	for(auto x : p) {
		int val0 = x.fi;
		int val1 = x.se;
		dp[0][u] += (val0 + 2);
	}
	
	dp[1][u] = 0;
	
	for(auto x : p) {
		int val0 = x.fi;
		int val1 = x.se;
		if(dp[1][u] != 0) dp[1][u] = min(dp[1][u], dp[0][u] - (val0 + 2) + (val1 + 1));
		else dp[1][u] = (dp[0][u] - (val0 + 2) + (val1 + 1));
	}
}


signed main() {
	fast_cin();
	
	freopen("STRANGE.INP", "r", stdin);
	freopen("STRANGE.OUT", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		f[x] = true;
	}
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	cout << min(dp[0][1], dp[1][1]);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}