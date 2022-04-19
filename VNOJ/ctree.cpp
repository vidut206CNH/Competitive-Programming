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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int mxc = 30;
const int inf = 1e18;

int n;
int dp[mxc + 5][MAXN1];
int res[MAXN1];
vector<int> adj[MAXN1];

void dfs(int u, int par) {

	for(int i = 1; i <= mxc; ++i) {
		dp[i][u] = i;
	}
	
	for(int v : adj[u]) {
		
		if(v == par) continue;
		
		dfs(v, u);
		for(int c = 1; c <= mxc; ++c) {
			int best = inf;
			for(int d = 1; d <= mxc; ++d) {
				if(d == c) continue;
				best = min(best, dp[d][v]);
			}
			
			dp[c][u] += best;
		}
		
	}
}

void calc(int u, int par, int color) {
	res[u] = color;
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		
		int color_v = 0, minn = inf;
		
		for(int c = 1; c <= mxc; ++c) {
			if(minn > dp[c][v] && c != color) {
				minn = dp[c][v];
				color_v = c;
			}
		} 
		
		calc(v, u, color_v);
		
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
	
	int ans = MOD;
	for(int i = 1; i <= mxc; ++i) {
		if(ans > dp[i][1]) ans = dp[i][1];
	}
	
	for(int c = 1; c <= mxc; ++c) {
		if(dp[c][1] == ans) {
			calc(1, -1, c);
			break;
		}
	}
	
	cout << ans << "\n";
	for(int i = 1; i <= n; ++i) cout << res[i] << "\n";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}