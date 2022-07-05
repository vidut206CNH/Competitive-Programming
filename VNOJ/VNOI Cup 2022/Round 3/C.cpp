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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,m;
vector<vector<int>> adj[MAXN1];
vector<int> g[MAXN1];
int res[MAXN1];
bool good = true;

void dfs(int x, int color) {
	res[x] = color;
	for(auto v : adj[x]) {
		
		if(color == 0) {
			if(res[v[0]] == 0) continue;
			
			dfs(v[0], 0);
		}
		
		else if(res[v[0]] == 0) {
			if(g[v[0]][0] != color) dfs(v[0], g[v[0]][0]);
			else if(sz(g[v[0]]) == 2) dfs(v[0], g[v[0]][1]);
			else good = false;
		}
		
	}
}

void solve(int x) {
	map<int,int> mp;
	vector<int> p;
	
	for(auto v : adj[x]) {
		mp[v[1]]++;
		if(v[1] != v[2]) mp[v[2]]++;
		if(mp[v[1]] == sz(adj[x])) g[x].push_back(v[1]);
		if(mp[v[2]] == sz(adj[x])) g[x].push_back(v[2]);
	}
	
	
}


void calc(int x) {
	for(int c : g[x]) {
		good = true;
		dfs(x, c);
		
		if(good) break;
		
		dfs(x, 0);
	}
}
int main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v,x,y;
		cin >> u >> v >> x >> y;
		adj[u].push_back({v, x, y});
		adj[v].push_back({u, x, y});
	}
	
	for(int i = 1; i <= n; ++i) {
		solve(i);
	}
	
	for(int i = 1; i <= n; ++i) {
		if(sz(g[i]) == 0) {
			res[i] = 1;
			continue;
		}
		
		if(res[i]) {
			continue;
		}
		
		calc(i);
	}
	
	bool ok = true;
	for(int i = 1; i <= n; ++i) ok &= (res[i] != 0);
	if(!ok) cout << -1;
	
	else for(int i = 1; i <= n; ++i) cout << res[i] << " ";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}