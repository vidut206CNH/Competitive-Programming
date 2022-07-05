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

int n;
vector<int> adj[MAXN1];
long long dp[MAXN1];
int a[MAXN1];
int root;


void dfs(int u, int par) {
	vector<pii> p;
	for(int v : adj[u]) {
		if(v == par) continue;
		dfs(v, u);
		
		p.push_back({dp[v], v});
	}
	
	sort(p.begin(), p.end(), greater<pii>());
	
	for(int i = 0; i < sz(p) && (u == root ? a[u] : a[u] - 1) > 0; ++i) {
		int v = p[i].se;
		long long val = p[i].fi;
		dp[u] += (2 + val);
		--a[u];
		--a[v];
	}
	
	for(int i = 0; i < sz(p) && (u == root ? a[u] : a[u] - 1) > 0;++i) {
		int v = p[i].se;
		if(a[v]) {
			int d = min(a[v], (u == root ? a[u] : a[u] - 1));
			dp[u] += 2*d;
			a[v] -= d;
			a[u] -= d;
		}
	}
/*	db(u);
	db(dp[u]);
	cerr << "\n";*/
}

int main() {
	fast_cin();
	
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} 
	
	cin >> root;
	
	dfs(root, -1);
	
	cout << dp[root];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}