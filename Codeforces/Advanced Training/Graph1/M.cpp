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

int n,m,s,t;
vector<pii> adj[MAXN1];
int dist[MAXN1];
bool P[MAXN1];



signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v,cost;
		cin >> u >> v >> cost;
		adj[u].push_back({v, cost});
	}
	
	cin >> s >> t;
	memset(dist, -1, sizeof dist);
	priority_queue<pii, vector<pii >, greater<pii> > pq;
	dist[s] = 0;
	pq.push({dist[s], s});
	
	while(!pq.empty()) {
		int u = pq.top().se;
		int val = pq.top().fi;
		
		pq.pop();
		
		if(P[u]) continue;
		P[u] = true;
		
		for(auto x : adj[u]) {
			int v = x.fi;
			int w = x.se;
			if(dist[v] == -1 || dist[v] > w + val) {
				dist[v] = w + val;
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