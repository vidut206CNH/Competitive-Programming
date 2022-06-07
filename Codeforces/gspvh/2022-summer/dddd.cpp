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

int n,p;
vector<int> adj[MAXN1];
long long down[MAXN1][35];
long long up[MAXN1][35];

void dfs1(int u, int par) {
	down[u][0] = 1;
	
	for(int v : adj[u]) {
		if(v == par) continue;
		dfs1(v, u);
		
		for(int rem = 0; rem < p; ++rem) {
			down[u][rem] += down[v][(rem - 1 + p)%p];
		}
		
	}
}


void dfs2(int u, int par) {
	up[u][0] += 1;
	
	vector<int> val(p, 0);
	
	for(int v : adj[u]) {
		if(v == par) continue;
		
		for(int rem = 0; rem < p; ++rem) {
			val[rem] += down[v][rem];
		}
	}
	
	for(int v : adj[u]) {
		if(v == par) continue;
		
		for(int rem = 0; rem < p; ++rem) {
			int rem1 = (rem - 2 + p)%p;
			int rem2 = (rem - 1 + p)%p;
			
			up[v][rem] += (val[rem1] - down[v][rem1]) + up[u][rem2];
		}
		
		dfs2(v, u);
	}
	
}

int main() {
	fast_cin();
	freopen("dddd.inp", "r", stdin);
	freopen("dddd.out", "w", stdout);
	
	cin >> n >> p;
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	
	for(int i = 1; i <= n; ++i) {
		long long sum = down[i][0] + up[i][0] - 1;
		cout << sum << " ";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}