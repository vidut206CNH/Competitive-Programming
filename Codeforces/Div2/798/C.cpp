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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;

int t;
int n;
vector<int> adj[MAXN1];
int sum[MAXN1];


void dfs(int u, int par) {
	sum[u] = 1;
	for(int v : adj[u]) {
		if(v == par) continue;
		dfs(v, u);
		sum[u] += sum[v];
	}
}

int calc(int u, int par) {
	if((sz(adj[u]) == 1) || (u != 1 && sz(adj[u]) == 2)) {
		return sum[u] - 1 - (sz(adj[u]) != 1 || u == 1);
	} 
	
	int child[2];
	int id = 0;
	for(int v : adj[u]) {
		if(v == par) continue;
		child[id++] = v;
	}
	int res = 0;
	for(int i = 0; i < 2; ++i) {
		res = max(res, sum[child[i]] - 1 + calc(child[1^i], u));
	}
	
	return res;
}

int main() {
	fast_cin();
	
	cin >> t;	
	
	while(t--) {
		cin >> n;

		// reset
		for(int i = 1; i <= n; ++i) adj[i].clear();
		for(int i = 2; i <= n; ++i) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		
		dfs(1, -1);
		
		cout << calc(1, -1) << "\n";
		
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}