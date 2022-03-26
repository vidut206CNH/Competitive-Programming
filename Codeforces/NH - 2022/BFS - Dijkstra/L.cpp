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

struct edge{
	int v,a,b,cost;
};

int n,m,s,t;
vector<edge> adj[MAXN1];
int dist[MAXN1];
bool P[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; ++i) {
		int u,v,a,b,cost;
		cin >> u >> v >> a >> b >> cost;
		adj[u].push_back({v, a, b, cost});
		adj[v].push_back({u, a, b, cost});
	}
	
	priority_queue<pii, vector<pii >, greater<pii > > pq;
	memset(dist, -1, sizeof dist);
	dist[s] = 0;
	pq.push({dist[s], s});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int node = pq.top().se;
/*		db(val);
		db(node);
		cerr << "\n";*/
		
		pq.pop();
		
		if(node == t) {
			cout << val;
			exit(0);
		}
		if(P[node]) continue;
		P[node] = true;
		
		for(auto edge : adj[node]) {
			int v = edge.v;
			int x = edge.a;
			int y = edge.b;
			int cost = edge.cost;
			
			if(cost > x) continue;
			
			int d = val;
			if(d%(x + y) >= x) {
				d = (d + x + y - 1)/(x + y)*(x + y);	
			}
			int q = d/(x + y);
			
			if(((d + cost) <= (x + y)*(q + 1)) && (d + cost)%(x + y) <= x && (dist[v] == -1 || dist[v] > d + cost)) {
				dist[v] = d + cost;
				pq.push({dist[v], v});
			}
			
			else if(d%(x+y)) {
				d = (d + x + y - 1)/(x + y)*(x + y);
				q = d/(x + y);
				if((d + cost) <= (x + y)*(q + 1) && (d + cost)%(x + y) <= x && (dist[v] == -1 || dist[v] > d + cost)) {
					dist[v] = d + cost;
					pq.push({dist[v], v});
				}
			}
		}
		
	}
	
	cout << -1;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}