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
const int MAXN2 = 5005;
const int inf = 1e18;

struct edge{
	int u,v,cost;
};

int n,m;
vector<pii > adj[MAXN1];
vector<int> E[MAXN1];

int dist[MAXN1][MAXN1];

int dp1[MAXN1][MAXN1];
int dp2[MAXN1][MAXN1];
edge p[MAXN2];

bool P[MAXN1];


void dijkstra(int x) {
	memset(dist[x], -1, sizeof dist[x]);
	memset(P, false, sizeof P);
	
	priority_queue<pii, vector<pii > , greater<pii > > pq;
	dist[x][x] = 0;
	dp1[x][x] = 1;
	E[x].clear();
	
	pq.push({dist[x][x], x});
	vector<pii > d;
	// calc dp1
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int u = pq.top().se;
		
		pq.pop();
		d.push_back({val, u});
		
		if(P[u]) continue;
		P[u] = true;
		
		for(auto ed : adj[u]) {
			int v = ed.fi;
			int w = ed.se;
			if(dist[x][v] >= val + w || dist[x][v] == -1) {
				if(dist[x][v] == val + w) {
					
					dp1[x][v] += dp1[x][u];
					E[v].push_back(u);
					
				} else {
					
					E[v].clear();
					E[v].push_back(u);
					dp1[x][v] = dp1[x][u];
					
					dist[x][v] = val + w;
					pq.push({dist[x][v], v});
				}
			}
		}
	}
	
	sort(d.begin(), d.end(), greater<pii > ());
	
	for(auto node : d) {
		int u = node.se;
		dp2[x][u] = (dp2[x][u] + 1)%MOD;
		for(auto v : E[u]) {
			dp2[x][v] = (dp2[x][v] + dp2[x][u])%MOD;
		}
	}	
	
	
}



signed main() {
	fast_cin();
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		p[i] = {u,v,c};
		adj[u].push_back({v,c});
	}

	
	for(int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	
	
	for(int i = 1; i <= m; ++i) {
		int u = p[i].u;
		int v = p[i].v;
		int cost = p[i].cost;
		int res = 0;
		for(int s = 1; s <= n; ++s) {
			if(dist[s][u] == -1) continue;
			if(dist[s][u] + cost == dist[s][v]) {
				res = (res + dp1[s][u]*dp2[s][v])%MOD;
			}
		}
		
		cout << res << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}