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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,k;
bool P[MAXN1];
int trace[MAXN1];
vector<pii > adj[MAXN1];
vector<int> dist(MAXN1, inf);
priority_queue<pii, vector<pii >, greater<pii > > pq;

void dijk(int s) {
	memset(P, false, sizeof P);
	memset(trace, -1, sizeof trace);
	dist.assign(MAXN1, inf);
	dist[s] = 0;
	pq.push({0, s});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int u = pq.top().se;
		pq.pop();
		
		if(P[u]) continue;
		P[u] = true;
		
		for(auto x : adj[u]) {
			int w = x.se;
			int v = x.fi;
			if(dist[v] > val + w) {
				dist[v] = val + w;
				trace[v] = u;
				pq.push({dist[v], v});
			}
		}
	}
}

signed main() {
	fast_cin();


	cin >> n >> m >> k;

	
	for(int i = 1; i <= m; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	
	while(k--) {
		int type, u, v;
		cin >> type >> u >> v;
		dijk(u);
		if(type == 0) {
			cout << dist[v] << "\n";
		}
		else {
			vector<int> path;
			while(v != -1) {
				path.push_back(v);
				v = trace[v];
			}
			reverse(path.begin(), path.end());
			cout << sz(path) << " ";
			for(auto x : path) cout << x << " ";
			cout << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}