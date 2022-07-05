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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int n,m;
int a[MAXN1];
int cost[MAXN1][MAXN1];
bool ok[MAXN1][MAXN1];
int visited[MAXN1];
vector<pii> adj[MAXN1];
int E[MAXN1];
vector<int> topo;

void dfs(int u) {
	
	visited[u] = true;
	for(pii x : adj[u]) {
		int v = x.fi;
		if(visited[v]) continue;
		dfs(v);
	}
	
	topo.emplace_back(u);
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		
		for(int j = 1; j < i; ++j) {
			if(a[i] > a[j]) ok[i][j] = true;
			if(a[i] < a[j]) ok[j][i] = true;
		}
		
	}
	
	memset(E, 0x3f, sizeof E);
	
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v, c;
		cin >> u >> v >> c;
		if(ok[u][v]) {
			adj[u].push_back({v, c});
			E[v] = min(E[v], c);
		}
	}
	
	for(int root = 1; root <= n; ++root) {
		
		memset(visited, false, sizeof visited);
		topo.clear();
		
		dfs(root);
		bool good = true;
		for(int i = 1; i <= n; ++i) good &= visited[i];
		
		if(!good) continue;
		
		reverse(topo.begin(), topo.end());
		
		int res = 0;
		E[topo[0]] = 0;
		for(int x : topo) {
			res += E[x];
		}
		cout << res;
		return 0;
	}
	
	cout << -1;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}