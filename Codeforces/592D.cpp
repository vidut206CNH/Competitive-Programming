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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e9 + 18;

int m,n;
vector<int> adj[MAXN1];
int down[MAXN1];
int up[MAXN1];
int s[MAXN1];
bool ok[MAXN1];
int cntE[MAXN1];

void dfs1(int u, int par) {
	
	down[u] = (ok[u] ? 0 : -inf);
	s[u] = ok[u];
	
	for(int v : adj[u]) {
		if(v == par) continue;
		dfs1(v, u);
		s[u] += s[v];		
		if(down[v] == -inf) continue;
		down[u] = max(down[u], down[v] + 1);
	}
	
}


void dfs2(int u, int par) {
	

	vector<int> p;
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		p.push_back(down[v]);
	}
	
	sort(p.begin(), p.end(), greater<int>());
	
	
	for(int v : adj[u]) {
		if(v == par) continue;
		
		cntE[v] = cntE[u];
		if(s[v] == 0) cntE[v]++;
		if(s[v] == m) cntE[v]--;
		
		up[v] = (ok[v] ? 0 : -inf);
		
		if(up[u] != -inf) {
			up[v] = max(up[v], up[u] + 1);
		}
		
		if(sz(p) > 1) {
			up[v] = max(up[v], (down[v] == p[0] ? p[1] : p[0]) + 2);
		}
		
		dfs2(v, u);
		
	}
	
}


int calc(int u) {
	return (cntE[u]*2 - max(up[u], down[u]));
}

int main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		ok[x] = true;
	}
	
	
	dfs1(1, -1);
	up[1] = -inf;
	for(int i = 2; i <= n; ++i) {
		if(s[i] > 0) cntE[1]++;
	}
	dfs2(1, -1);
	int best = inf, res = -1;
	for(int i = 1; i <= n; ++i) {
		if(calc(i) < best) {
			best = calc(i);
			res = i;
		}
	}
	
	cout << res << "\n" << best;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}