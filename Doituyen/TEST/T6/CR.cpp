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
vector<pii> adj[MAXN1];
int down[2][MAXN1];
int up[2][MAXN1];
long long res = 0;

void dfs1(int u, int par) {
	
	for(auto X : adj[u]) {
		int v = X.fi;
		int c = X.se;
		
		if(v == par) continue;
		dfs1(v, u);
		
		if(c == 1) {
			down[1][u] += (down[1][v] + 1);
		}
		
		else {
			down[0][u] += (1 + down[0][v]);
		}
	}
}

void dfs2(int u, int par) {
	
	res += 1LL*(down[0][u])*(up[1][u]);
	res += 1LL*(down[1][u])*(up[0][u]);
	res += 1LL*down[0][u]*down[1][u];
	
	vector<int> p[2];
	for(auto X : adj[u]) {
		
		int v = X.fi;
		int c = X.se;
		if(v == par) continue;
		
		if(c == 0) p[0].push_back(down[0][v] + 1);
		if(c == 1) p[1].push_back(down[1][v] + 1);
	}
	
	long long sum0 = 1, sum1 = 1;
	
	for(int i = 0; i < sz(p[0]); ++i) {
		res += 1LL*sum0*p[0][i]*2;
		sum0 += p[0][i];
	}
	
	for(int i = 0; i < sz(p[1]); ++i) {
		res += 1LL*sum1*p[1][i]*2;
		sum1 += p[1][i];
	}
	
	for(auto X : adj[u]) {
		int v = X.fi;
		int c = X.se;
		
		if(v == par) continue;
		
		if(c == 1) {
			up[1][v] = (up[1][u] + down[1][u] - down[1][v]);
		}
		
		else up[0][v] = (up[0][u] + down[0][u] - down[0][v]);
		
		dfs2(v, u);
	}
	
	
}


int main() {
	
/*	freopen("CR.INP", "r", stdin);
	freopen("CR.OUT", "w", stdout);*/
	
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}