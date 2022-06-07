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

int n;
int A,B;
vector<int> adj[MAXN1];
bool spec[MAXN1];
int down[MAXN1];
int h[MAXN1];
int dpup[MAXN1];

int res = 0;

void dfs1(int u, int par) {
	spec[u] = (u == B);
	down[u] = 1;
	
	for(int v : adj[u]) {
		
		if(v == par) continue;
		
		h[v] = h[u] + 1;
		
		dfs1(v, u);
		
		down[u] = max(down[u], down[v] + 1);	
		spec[u] |= (spec[v]);
		
	}
	
}

void dfs2(int u, int par) {
	int node = -1;
	int best = 0;
	for(int v : adj[u]) {
		if(v == par) continue;
		
		if(spec[v]) node = v;
		else best = max(best, down[v]);
		
	}
	
	if(u != A) {		
		int val;
		if(u == B) val = best + 1;
		else val = best + h[B] - h[u] + 1;
		
		res = max(res, min(val, dpup[u]));
	}
	
	if(node == -1) return;
	
	dpup[node] = max(dpup[node], best + h[u] + 1);
	dfs2(node, u);
	
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	
	cin >> A >> B;
	dfs1(A, -1);
	
	for(int v : adj[A]) {
		
		if(!spec[v]) {
			dpup[A] = max(dpup[A], down[v] + 1);
		}
		
	}
	
	dfs2(A, -1);
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}