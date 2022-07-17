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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;

int n,k;
int c[MAXN1];
long long dp[MAXN1];
vector<int> adj[MAXN1];

bool check(int pos, int mask) {
	if(c[pos] > 20) return false;
	return (mask >> c[pos])&1;
}

void dfs(int u, int par, int mask) {
	
	if(!check(u, mask)) dp[u] = 1;
	
	
	for(int v : adj[u]) {
		if(v == par) continue;
		
		dfs(v, u, mask);
		
		long long tmp = 1 + dp[v];
		
		dp[u] = dp[u]*tmp%MOD;
		
	}
}

int main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
		c[i]--;
	}
	
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	long long res = 0;
	
	for(int mask = 0; mask < (1 << k); ++mask) {
		memset(dp, 0, sizeof dp);
		dfs(1, -1, mask);
		long long sum = 0;
		for(int i = 1; i <= n; ++i) sum = (sum + dp[i])%MOD;
		
		
		if(__builtin_popcount(mask)%2 == 0) res = (res + sum)%MOD;
		else res = (res - sum + MOD)%MOD;
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}