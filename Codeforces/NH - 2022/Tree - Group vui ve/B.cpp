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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
vector<pii> adj[MAXN1];
int dp1[MAXN1];
int dp2[MAXN1];

void dfs1(int u, int p) {
	for(auto x : adj[u]) {
		int v = x.fi;
		int val = x.se;
		if(v == p) continue;
		dfs1(v, u);
		dp1[u] += val + dp1[v];
	}
}


void dfs2(int u, int p) {
	
	for(auto x : adj[u]) {
		int v = x.fi;
		int val = x.se;
		
		if(v == p) continue;
		dp2[v] = dp2[u] + (dp1[u] - dp1[v] - val) + (val == 1 ? 0 : 1);
		dfs2(v, u);
	}
	
}
signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, 1});
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	vector<int> p;
	int res = inf;
	for(int i = 1; i <= n; ++i) {
		if(dp1[i] + dp2[i] < res) {
			res = dp1[i] + dp2[i];
			p.clear();
		}
		
		if(dp1[i] + dp2[i] == res) {
			p.push_back(i);
		}
	}
	
	
	cout << res << "\n";
	for(auto x : p) cout << x << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}