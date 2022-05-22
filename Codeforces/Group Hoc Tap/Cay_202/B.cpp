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

int n;
vector<pii> adj[MAXN1];
int a[MAXN1];
int dp[MAXN1];
int f[MAXN1];

void dfs1(int u, int par) {
	
	for(auto x : adj[u]) {
		int v = x.fi;
		int c = x.se;
		
		if(v == par) continue;
		
		f[v] = max(0LL, f[u] + c);
		
		dfs1(v,u);
	}
}


void dfs2(int u, int par) {
	
	dp[u] = 1;
	
	for(auto x : adj[u]) {
		int v = x.fi;
		int c = x.se;
		
		if(v == par) continue;
		
		dfs2(v, u);
		
		if(f[u] + c <= a[v]) {
			dp[u] += (dp[v]);
		}
		
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for(int u = 2; u <= n; ++u) {
		int v,c;
		cin >> v >> c;
		adj[u].push_back({v,c});
		adj[v].push_back({u, c});
	}
	
	dfs1(1, -1);
	
	dfs2(1, -1);
	
	cout << n - dp[1];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}