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
const int MAXN1 = 5005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,q;
int dist[MAXN1][(1 << 11) + 5];
vector<pii> adj[MAXN1];
int city[MAXN1];

struct state{
	int node, val, mask;
};

struct comp{
	
	bool operator() (const state& A, const state& B) const {
		return A.val > B.val;
	}
	
};


signed main() {
	fast_cin();

	
	memset(dist, -1, sizeof dist);
	cin >> n >> m >> q;
	
	++q;
	memset(city, -1, sizeof city);
	
	for(int i = 0; i < q - 1; ++i) {
		int x;
		cin >> x;
		city[x] = i;
	}
	
	city[1] = q - 1;
	
	
	
	for(int i = 1; i <= m; ++i) {
		int u,v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	
	// dijkstra
	
	priority_queue<state, vector<state>, comp> pq;
	dist[1][0] = 0;
	pq.push({1, 0, 0});
	
	
	while(!pq.empty()) {
		int u = pq.top().node;
		int val = pq.top().val;
		int mask = pq.top().mask;
		
		pq.pop();
		
		if(dist[u][mask] != -1 && val > dist[u][mask]) continue;
		
		for(auto x : adj[u]) {
			int v = x.fi;
			int w = x.se;
			int mask1 = mask;
			
			if(city[v] != -1) mask1 |= (1 << city[v]);
			
			if(dist[v][mask1] == -1 || dist[v][mask1] > val + w) {
				dist[v][mask1] = val + w;
				pq.push({v, dist[v][mask1], mask1});
			}
		}
		
	}
	
	cout << dist[1][(1 << q) - 1];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
