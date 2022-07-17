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
vector<int> adj[MAXN1];
int color[MAXN1];
int par[MAXN1];
int h[MAXN1];
vector<int> nodes;
pair<int, pii> S[MAXN1][3][3];

void ff(int u, bool state, pair<int, pii> val) {
	S[u][state][2] = val;
	sort(S[u][state], S[u][state] + 3);
}

bool dfs(int u) {
	color[u] = 1;
	
	for(int c = 0; c < 2; ++c) {
		S[u][c][0] = S[u][c][1] = S[u][c][2] = {1e9, {-1, -1}};	
	}
	
	for(int v : adj[u]) {
		
		if(v == par[u]) continue;
		
		if(color[v] == 0) {
			par[v] = u;
			h[v] = h[u] + 1;
			if(dfs(v)) return true;
			
			ff(u, 0, S[v][1][0]);
			ff(u, 1, S[v][0][0]);
		}
		
		else if(color[v] == 1) {
			nodes.clear();
			
			int p = u;
			while(true) {
				nodes.push_back(p);		
				if(p == v) break;	
				p = par[p];
			}
			
			if(sz(nodes)%2 == 0) return true;
			
			else {
				ff(u, h[p]%2, {h[p], {u, p}});
			}
		}
	}
	
	
	for(int c = 0; c < 2; ++c) {
		if(S[u][c][1].fi <= h[u] && S[u][c][0].fi < h[u]) {
			nodes.clear();
			vector<int> d[3];
			
			for(int i = 0; i < 2; ++i) {
				int p = S[u][c][i].se.fi;
				while(p != u) {
					d[i].push_back(p);
					p = par[p];
				}
			}
			
			int u1 = S[u][c][1].se.se;
			int v1 = S[u][c][0].se.se;
			
			while(true) {
				d[2].push_back(u1);
				if(u1 == v1) break;
				u1 = par[u1];
			}
			
			
			reverse(d[1].begin(), d[1].end());
			bool ok = false;
			
			for(int v : d[1]) {nodes.push_back(v);ok |= (v == u);}
			for(int v : d[2]) {nodes.push_back(v); ok |= (v == u);}
			for(int v : d[0]) {nodes.push_back(v); ok |= (v == u);}
			
			if(!ok) nodes.push_back(u);
			if(sz(nodes)%2 == 0) return true;
			
		}
		
	}
	
	color[u] = 2;
		
	return false;

}


int main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	
	for(int i = 1; i <= n; ++i) {
		if(!color[i]) {
			if(dfs(i)) {
				cout << "YES\n";
				cout << sz(nodes) << "\n";
				for(auto x : nodes) cout << x << " ";
				return 0;
			}
		}
	}
	
	cout << "NO";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}