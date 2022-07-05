/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int n,m;
vector<pair<int,char> > adj[30];
int dist[30][30];

int main() {
	fast_cin();
	
	cin >> n >> m;
	queue<pii> q;
	
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		char c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	memset(dist, -1, sizeof dist);
	dist[1][2] = 0;
	q.push({1, 2});
	int res = MOD;
	
	while(!q.empty()) {
		int u = q.front().fi;
		int v = q.front().se;
		
		q.pop();
		
		for(auto X : adj[u]) {
			for(auto Y : adj[v]) {
				
				if(X.se != Y.se) {
					continue;
				}
				
				int u1 = X.fi;
				int v1 = Y.fi;
				
/*				db(u);
				db(v);
				db(u1);
				db(v1);
				db(dist[u][v]);
				cerr  << "\n";*/
				
				if(u1 == v1) {
					res = min(res, dist[u][v] + 2);
				}
				
				else if(u1 == v && v1 == u) {
					res = min(res, dist[u][v] + 1);
				}
				
				else if(dist[u1][v1] == -1) {
					dist[u1][v1] = dist[u][v] + 2;
					q.push({u1, v1});
				} 
			}
		}
	}
	
	cout << (res == MOD ? -1 : res);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}