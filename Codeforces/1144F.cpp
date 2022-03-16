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
vector< int > adj[MAXN1];
int color[MAXN1];
int res[MAXN1];
pii d[MAXN1];
bool bad = false;

void bfs(int x) {
	
	color[x] = 0;
	queue<int> q;
	q.push(x);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : adj[u]) {
			if(color[v] == color[u]) {
				bad = true;
				return;
			}
			if(color[v] == -1) {
				color[v] = color[u]^1;
				q.push(v);
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
		d[i] = {u,v};
	}
	
	// solve
	memset(color, -1, sizeof color);
	for(int i = 1; i <= n; ++i) {
		if(color[i] == -1) {
			bfs(i);
		}
	}
	
	if(bad) return cout << "NO", 0;
	
	cout << "YES\n";
	for(int i = 1; i <= m; ++i) {
		int u = d[i].fi;
		if(color[u] == 0) cout << 1;
		else cout << 0;
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}