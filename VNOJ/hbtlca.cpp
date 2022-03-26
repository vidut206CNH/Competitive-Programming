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

int n,q;
vector<int> adj[MAXN1];
int up[MAXN1][20];
int h[MAXN1];


void dfs(int u) {
	for(auto v : adj[u]) {
		if(v == up[u][0]) continue;
		h[v] = h[u] + 1;
		
		up[v][0] = u;
		
		for(int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
		
		dfs(v);
	}
}


int lca(int u, int v) {
	if(h[u] < h[v]) swap(u,v);
	
	int diff = h[u] - h[v];
	
	for(int i = 0; (1 << i) <= diff; ++i) {
		if(diff >> i & 1) u = up[u][i];
	}
	
	if(u == v) return u;
	
	int d = log2(h[u]) + 1;
	
	while(d >= 0) {
		if(up[u][d] != up[v][d]) {
			u = up[u][d];
			v = up[v][d];
		}
		--d;
	}
	
	return up[u][0];
	
}

signed main() {
	fast_cin();
	while(cin >> n) {
		if(n == 0) break;
		for(int i = 1; i <= n; ++i) adj[i].clear();
		
		for(int i = 1; i < n; ++i) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int root = 1;
		up[1][0] = 0;
		dfs(root);
		
		cin >> q;
		while(q--) {
			char c;
			cin >> c;
			if(c == '!') {
				int x;
				cin >> x;
				root = x;
			}
			else {
				int u,v;
				cin >> u >> v;
				vector<int> tmp;
				tmp.push_back(lca(root, u));
				tmp.push_back(lca(root, v));
				tmp.push_back(lca(u,v));
				sort(tmp.begin(), tmp.end());
				
				if(tmp[0] == tmp[1]) cout << tmp.back() << "\n";
				else cout << tmp[0] << "\n";
			}
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}