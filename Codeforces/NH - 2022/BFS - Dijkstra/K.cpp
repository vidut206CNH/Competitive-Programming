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
const int MAXN1 = 5005;
const int MAXN2 = 1e6+5;

int n,m;
pii a[MAXN1];
vector<int> adj[MAXN1];
vector<int> E[MAXN1];
bool P[MAXN1];
int dist[MAXN1];
int d[MAXN1];

queue<int> q;

void solve(int id) {
	// init
	for(int i = 1; i <= n; ++i) d[i] = -1;
	
	d[id] = 0;
	q.push(id);
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		
		if(d[node] == a[id].se) break;
		
		for(auto x : adj[node]) {
			if(d[x] != -1) continue;
			d[x] = 1 + d[node];
			q.push(x);
		}
	}
	
	while(!q.empty()) q.pop();
	
	for(int i = 1; i <= n; ++i) {
		if(d[i] != -1 && i != id) {
			E[id].push_back(i);
		}
	}
}

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
	}
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	// bfs
	for(int i = 1; i <= n; ++i) {
		solve(i);
	}
	
	
	// dijkstra
	memset(dist, -1, sizeof dist);
	priority_queue<pii, vector<pii > , greater<pii > > pq;
	pq.push({0, 1});
	dist[1] = 0;
	while(!pq.empty()) {
		int node = pq.top().se;
		int val = pq.top().fi;
		
		pq.pop();
		
		if(P[node]) continue;
		P[node] = true;
		
		for(auto v : E[node]) {
			if(dist[v] == -1 || dist[v] > val + a[node].fi) {
				dist[v] = val + a[node].fi;
				pq.push({dist[v], v});
			}
		}
	}
	
	cout << dist[n];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}