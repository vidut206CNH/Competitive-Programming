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


int n;
vector<int> adj[MAXN1];
int dp[2][MAXN1];


void dfs(int cur = 1, int par = 0) {
	int white=1,black=1;
	
	for(auto x : adj[cur]) {
		if(x == par) continue;
		
		dfs(x, cur);
		white = white*(dp[0][x] + dp[1][x])%MOD;
		black = black*dp[0][x]%MOD;	
	}
	
	dp[0][cur] = white;
	dp[1][cur] = black;
/*	
	db(white);
	db(black);
	cerr << "\n";*/
}

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	
	dfs();
	
	cout << (dp[0][1] + dp[1][1])%MOD;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}