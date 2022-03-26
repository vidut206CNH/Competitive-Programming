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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


struct edge{
	int u,v, cost;
	
	bool operator() (const edge &A, const edge &B) {
		return A.cost < B.cost;
	}
};

vector<pii > adj[MAXN1];
int n,m,k;
int dist[MAXN1];
bool P[MAXN1];
priority_queue<pii, vector<pii>, greater<pii > > pq;
vector<int> res;

void dijkstra(int node) {
	dist[node] = 0;
	pq.push({dist[node], node});
	vector<int> tmp;
	
	while(!pq.empty()) {
		int u = pq.top().se;
		int val = pq.top().fi;
		
		pq.pop();
		if(P[u]) continue;
		P[u] = true;
		
		tmp.push_back(u);
		
		for(auto x : adj[u]) {
			int v = x.fi;
			int cost = x.se;
			if(dist[v] == -1 || dist[v] > val + cost) {
				dist[v] = val + cost;
				pq.push({dist[v], v});
			}
		}
	}
	
	for(auto x : tmp) {
		//db(x);
		P[x] = false;
		if(x != node) res.push_back(dist[x]);
		dist[x] = -1;
	}
}


signed main() {
	fast_cin();
	
	cin >> n >> m >> k;
	vector<edge> d;
	
	for(int i = 1; i <= m; ++i) {
		int u,v,cost;
		cin >> u >> v >> cost;
		d.push_back({u,v,cost});	
	}	
	
	sort(d.begin(), d.end(), edge());
	
	for(int i = 0; i < k; ++i) {
		int u = d[i].u;
		int v = d[i].v;
		int cost = d[i].cost;
		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
	}
	memset(P, false, sizeof P);
	memset(dist, -1, sizeof dist);
	
	for(int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	
	sort(res.begin(), res.end());
	cout << res[2*(k - 1)];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}