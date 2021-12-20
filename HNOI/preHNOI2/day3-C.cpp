/* 
	link problem: 
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
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 2e5 + 5;

struct node{
	int u, w;
	bool operator() (node &A, node &B) {
		return A.w > B.w;
	}
};

unordered_map<int, int> E[MAXN2];
vector<pii > edg;
vector<int> dist;
vector<bool> P;

void dijk() {
	dist.assign(MAXN2, INF);
	P.assign(MAXN2, 0);
	priority_queue<node, vector<node>, node > p;
	dist[1] = 0;
	p.push({1, dist[1]});
	while(!p.empty()) {
		node cur = p.top();
		p.pop();
		
		if(P[cur.u]) continue;
		P[cur.u] = 1;
		
		for(auto id : E[cur.u]) {
			int v = id.fi;
			int w = id.se;
			if(dist[v] > cur.w + w) {
				dist[v] = cur.w + w;
				p.push({v, dist[v]});
			}
		}
		
	}
}


signed main() {
	fast_cin();
	int n,m,q;
	cin >> n >> m >> q;
	edg.pb({0,0});
	for(int i=1;i<=m;++i) {
		int u,v,c;
		cin >> u >> v >> c;
		E[u][v] = c;
		E[v][u] = c;
		edg.pb({u,v});
	}
	
	
	for(int i=1;i<=q;++i) {
		int t,x;
		cin >> t >> x;
		int u = edg[t].fi;
		int v = edg[t].se;
		int g = E[u][v];
		E[u][v] = x;
		E[v][u] = x;
		dijk();
		cout << dist[n] << "\n";
		E[u][v] = g;
		
	}
	

	
	return 0;
}