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

int t;
int n,k;

vector<int> adj[MAXN1];
bool p[MAXN2];
int f[MAXN1];
bool Y[MAXN1];


void dfs(int u, int par, int y) {
	if(u == y) Y[u] = true;
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		dfs(v, u, y);
		
		p[u] |= p[v];
		Y[u] |= Y[v];
		 
		if(p[v]) {
			if(Y[v]) f[u] += 1;
			else f[u] += 2;
			f[u] += f[v];
		}
	}
	
/*	db(u);
	db(f[u]);
	cerr << "\n";*/
	
}

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int x,y;
		cin >> n >> k >> x >> y;
		for(int i = 1; i <= n; ++i) adj[i].clear();		
		for(int i = 1; i <= n; ++i) p[i] = false;
		for(int i = 1; i <= n; ++i) Y[i] = false;
		
		for(int i = 1; i <= n; ++i) f[i] = 0;
		
		for(int i = 1; i <= k; ++i) {
			int d;
			cin >> d;
			p[d] = true;
		}
		
		p[y] = true;
		
		for(int i = 1; i < n; ++i) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(x, -1, y);
		
		cout << f[x] << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}