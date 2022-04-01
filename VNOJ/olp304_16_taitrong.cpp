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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e9 + 7;

int n,m,s,t;
vector<pii> adj[MAXN1];
bool ok[MAXN1];
int dist[MAXN1];

signed main() {
	fast_cin();
	
	freopen("TAITRONG.INP", "r", stdin);
	freopen("TAITRONG.OUT", "w", stdout);
	
	cin >> n >> m >> s >> t;
	
	for(int i = 1; i <= m; ++i) {
		int u,v,cost;
		cin >> u >> v >> cost;
		adj[u].push_back({v,cost});
		adj[v].push_back({u, cost});
	}
	
	priority_queue<pii> pq;
	dist[s] = inf;
	pq.push({dist[s], s});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int u = pq.top().se;
		
		pq.pop();
		
		if(ok[u]) continue;
		ok[u] = true;
		
		
		for(auto x : adj[u]) {
			int v = x.fi;
			int cost = x.se;
			cost = min(cost, val);
			
			if(dist[v] < cost) {
				dist[v] = cost;
				pq.push({dist[v], v});
			}
		}
	}
	
	cout << dist[t];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}