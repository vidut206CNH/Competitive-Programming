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

int n,m;
vector<int> adj[MAXN1];
int f[MAXN1];
bool visited[MAXN1];

void dfs(int cur = 1, int par = 0) {
	
	if(visited[cur]) return;
	visited[cur] = 1;
	
	int prod = 1;
	bool child = 0;

	for(auto x : adj[cur]) {
		if(x == par) continue;

		dfs(x, cur);
		
		prod *= (f[x]);
	}
	
	f[cur] = prod;
	cerr << cur << " " << f[cur] << "\n"; 
}

signed main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs();
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}