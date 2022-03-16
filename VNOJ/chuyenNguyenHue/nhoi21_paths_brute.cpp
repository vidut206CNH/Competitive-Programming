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

int dist[MAXN1][MAXN1];
int cnt[MAXN1][MAXN1];

edge p[MAXN2];
bool op[MAXN1];

priority_queue<pii, vector<pii >, greater<pii > > pq;


void dijkstra(int x) {
	memset(dist[x], -1, sizeof dist[x]);
	memset(op, false, sizeof op);
	dist[x][x] = 0;
	cnt[x][x] = 1;
	pq.push({0, x});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int u = pq.top().se;
		
		pq.pop();
		if(op[u]) continue;
		op[u] = true;
		
		for(auto next : adj[u]) {
			int v = next.fi;
			int w = next.se;
			if(dist[x][v] >= val + w || dist[x][v] == -1) {
				if(dist[x][v] == val + w) cnt[x][v] += cnt[x][u];
				else cnt[x][v] = cnt[x][u];
				dist[x][v] = val + w;
				pq.push({dist[x][v], v});
			}
		}
	}
}


bool check(int u, int v) {
	return (dist[u][v] == -1);
}

signed main() {
	fast_cin();
	
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v, cost;
		cin >> u >> v >> cost;
		p[i] = {u,v, cost};
		
		adj[u].push_back({v,cost});
	}
	
	for(int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
/*			db(i);
			db(j);
			db(cnt[i][j]) << "\n";*/
		}
	}
	
	for(int i = 1; i <= m; ++i) {
		int n1 = p[i].u;
		int n2 = p[i].v;
		int cost = p[i].cost;
		int res = 0;
		for(int u = 1; u <= n; ++u) {
			for(int v = 1; v <= n; ++v) {
				if(check(u,v)) continue;
				
				if(!check(u, n1) && !check(n2, v) && (dist[u][v] == dist[u][n1] + dist[n2][v] + cost)) {
					res = (res + cnt[u][n1]*cnt[n2][v])%MOD;
				}
			}
		}
		
		cout << res << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
