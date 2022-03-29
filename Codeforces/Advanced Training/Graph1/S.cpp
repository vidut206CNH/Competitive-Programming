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
const int MAXN1 = 1505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


struct edge{
	int u,v,cost;
};

int n,m;
vector<pii > adj[MAXN1];
int dp1[MAXN1][MAXN1];
int dp2[MAXN1][MAXN1];
bool ok[MAXN1];
int dist[MAXN1][MAXN1];
edge p[5005];

void dfs(int node, int u) {
	
	if(dp2[node][u] != 0) return;
	
	dp2[node][u] = 1;
	
	for(auto x : adj[u]) {
		int v = x.fi;
		int cost = x.se;
		if(dist[node][v] == dist[node][u] + cost) {
			dfs(node, v);
			dp2[node][u] = (dp2[node][u] + dp2[node][v])%MOD;		
		}
	}
}

void solve(int node) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	memset(dist[node], -1, sizeof dist[node]);
	memset(ok, false, sizeof ok);
	
	dist[node][node] = 0;
	pq.push({dist[node][node], node});
	
	dp1[node][node] = 1;
	while(!pq.empty()) {
		int u = pq.top().se;
		int val = pq.top().fi;
		
		pq.pop();
		
		if(ok[u]) continue;
		ok[u] = true;
		
		for(auto x : adj[u]) {
			int v = x.fi;
			int cost = x.se;
			if(dist[node][v] == -1 || dist[node][v] > val + cost) {
				dist[node][v] = val + cost;
				dp1[node][v] = dp1[node][u]%MOD;
				pq.push({dist[node][v], v});
			}
			else if(dist[node][v] == val + cost) {
				dp1[node][v] = (dp1[node][u] + dp1[node][v])%MOD;
			}
		}
	}
	
	dfs(node, node);
	
}

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({v, cost});
		p[i] = {u, v, cost};
	}	
	
	for(int i = 1; i <= n; ++i) {
		solve(i);
	}
	
	for(int i = 1; i <= m; ++i) {
		int u = p[i].u;
		int v = p[i].v;
		int cost = p[i].cost;
		int res = 0;
		
		for(int s = 1; s <= n; ++s) {
			if(dist[s][u] != -1 && dist[s][v] != -1 && dist[s][u] + cost == dist[s][v]) {
				res = (res + dp1[s][u]*dp2[s][v]%MOD)%MOD;
			}
		}
		
		cout << res << "\n";
	}
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}