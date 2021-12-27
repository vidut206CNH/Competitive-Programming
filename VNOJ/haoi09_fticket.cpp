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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 5e3 + 5;
const int MAXN2 = 1e6+5;


struct node{
	int v,w;
};

int n,m;
vector<node > E[MAXN1];
vector<int> dist[2];
bool P[MAXN1];



void dijk(bool d) {
	memset(P, 0, sizeof P);
	
	dist[d].assign(MAXN1, INF);
	
	priority_queue<pii, vector<pii >, greater<pii > > p;
	
	if(d) {
		dist[d][n] = 0;
		p.push({dist[d][n], n});
	} else {
		dist[d][1] = 0;
		p.push({dist[d][1], 1});
	}
	
	while(!p.empty()) {
		pii cur = p.top();
		p.pop();
		
		//cout << cur.se << "\n";
		
		if(P[cur.se]) continue;
		P[cur.se] = 1;
		
		for(auto ed : E[cur.se]) {
			
			if(dist[d][ed.v] > cur.fi + ed.w) {
				dist[d][ed.v] = cur.fi + ed.w;
				p.push({dist[d][ed.v], ed.v});
				//cout << ed.v << " ";
			}
			
		}
		
		
	}
	
	
}


signed main() {
	fast_cin();
	cin >> n >> m;
	for(int i=1;i<=m;++i) {
		int u,v,c;
		cin >> u >> v >> c;
		
		E[u].push_back({v,c});
		E[v].push_back({u,c});
		
	}
	
	dijk(0);
	dijk(1);		
	int res = INF;
	
	for(int i=1;i<=n;++i) {
		for(auto e : E[i]) {
			res = min(res, dist[0][i] + dist[1][e.v]);
			res = min(res, dist[1][i] + dist[0][e.v]);
		}
	}
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}