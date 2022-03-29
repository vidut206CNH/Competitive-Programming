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

const int MOD = 666013;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
vector<int> adj[MAXN1];
int dp[MAXN1];
int dp2[MAXN1];
int f[MAXN1];

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return res;
}

int C(int k, int g) {
	return f[g]*power(f[k], MOD - 2)%MOD*power(f[g - k], MOD - 2)%MOD;
}


void dfs(int u, int p) {
	dp[u] = 1;
	
	for(auto v : adj[u]) {
		if(v == p) continue;
		
		dfs(v, u);
		
		dp[u] += dp[v];
	}
/*	db(u);
	db(dp[u]);
	cerr << "\n";*/
	
}

void dfs2(int u, int p) {
	dp2[u] = 1;
	
	int sum = 0;
	int total = dp[u] - 1;
	
	for(auto v : adj[u]) {
		if(v == p) continue;
		
		dfs2(v, u);
		dp2[u] = (dp2[u]*dp2[v]%MOD*C(dp[v], total - sum))%MOD;
		
		sum += dp[v];
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
	
	dfs(1, -1);
	
	f[0] = 1;
	for(int i = 1; i <= n; ++i) {
		f[i] = f[i - 1]*i%MOD;
	}
	
	dfs2(1, -1);
	cout << dp2[1]%MOD;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}