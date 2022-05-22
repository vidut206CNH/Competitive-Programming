/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
//const int inf = 1e18;

vector<int> topo;
bool visited[MAXN2];
int e[MAXN2];
vector<int> adj[MAXN2];
int dp[MAXN2];
int cnt[MAXN2];

void dfs(int v) {
	
    visited[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    
    topo.push_back(v);
    
}

int n,m,p;

signed main() {
	fast_cin();
	
	cin >> n >> m >> p;
	for(int i = 1; i <= p; ++i) cin >> e[i];
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}	
	
	for(int u = 1; u <= n; ++u) {
		if(visited[u] == false) {
			dfs(u);
		}
	}
	
	reverse(topo.begin(), topo.end());
	
	int c = 0;
	for(auto u : topo) {
		c += (u == e[c + 1]);
		cnt[u] = c;
/*		db(u);
		db(cnt[u]);
		cerr << "\n";*/
	}
	
	dp[1] = 1;
	
	for(auto u : topo) {
/*		db(dp[u]);
		db(u);*/
		for(auto v : adj[u]) {
			if((cnt[v] - cnt[u] == 0) || ((cnt[v] - cnt[u] == 1) && (v == e[cnt[v]]))) {
				//db(v);
				dp[v] = (dp[v] + dp[u])%MOD;
			}
			
		}
		
		//cerr << "\n";
	}
	
	
	cout << dp[n];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}