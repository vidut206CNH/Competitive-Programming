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
int dp1[MAXN1];
int dp2[MAXN1];
int res = 0;


int power(int a, int b) {
	int c = 1;
	while(b) {
		if(b&1) c = c*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return c;
}

void dfs1(int u, int p) {
	dp1[u] = 1;
	
	for(auto ed : adj[u]) {
		int v = ed.fi;
		int w = ed.se;
		
		if(v == p) continue;
		dfs1(v, u);
		dp1[u] = (dp1[u] + w*dp1[v]%MOD)%MOD;
	}
	int sum = 0;
	
	for(auto ed : adj[u]) {
		int v = ed.fi;
		int w = ed.se;
		
		if(v == p) continue;
		sum = (sum + dp1[v]*w%MOD*((dp1[u] - 1 - w*dp1[v] + MOD*MOD)%MOD))%MOD;
	}
	res = (res + sum*power(2, MOD - 2)%MOD)%MOD;
	
	res = (res + dp1[u] - 1 + MOD)%MOD;
}




signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}	
	
	dfs1(1, -1);

	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}