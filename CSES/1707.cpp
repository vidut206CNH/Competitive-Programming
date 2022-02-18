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
const int MAXN1 = 2505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;
vector<int> adj[MAXN1];
int d[MAXN1];
int p[MAXN1];
queue<int> q;
int res = inf;

void bfs(int node) {
	memset(d, -1, sizeof d);
	memset(p ,-1, sizeof p);
	
	q.push(node);
	d[node] = 0;
	p[node] = 0;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
/*		db(cur);
		cerr << "\n";*/
		
		for(auto x : adj[cur]) {
			if(d[x] == -1) {
				d[x] = d[cur] + 1;
				p[x] = cur;
				q.push(x);
			}
			else if(p[x] != cur && p[cur] != x) {
				res = min (res, d[x] + d[cur] + 1);
			}
		}
	}
	
}

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i) {
		bfs(i);
	}
	
	if(res != inf) cout << res;
	else cout << -1;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}