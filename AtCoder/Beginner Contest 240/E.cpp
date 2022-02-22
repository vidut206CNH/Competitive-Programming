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


int n,m;
vector<pii > adj[MAXN1];
int h[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= n ;++i) cin >> h[i];
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		if(h[u] >= h[v]) {
			adj[u].push_back({v, 0});
			adj[v].push_back({u, h[u] - h[v]});
		} else {
			adj[v].push_back({u, 0});
			adj[u].push_back({v, h[v] - h[u]});
		}
	}
	vector<int> dist(n + 5, inf);
	vector<bool> P(n + 5, false);
	
	priority_queue<pii, vector<pii >, greater<pii > > pq;
	dist[1] = 0;
	pq.push({0, 1});
	
	while(!pq.empty()) {
		int val = pq.top().fi;
		int cur = pq.top().se;
		
		pq.pop();
		
		if(P[cur]) continue;
		P[cur] = true;
		
		
		for(auto x : adj[cur]) {
			int v = x.fi;
			int w = x.se;
			
			if(dist[v] > w + val) {
				dist[v] = w + val;
				pq.push({dist[v], v});
			}
		}
	}
	
	int res = -inf;
	for(int i = 1; i <= n; ++i) {
		res = max(res, -(dist[i] - h[1] + h[i]));
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}