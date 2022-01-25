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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n,q;
vector<pii > adj[MAXN1];
bool visited[MAXN1];
int sum[MAXN1];

void dfs(int node) {
	
	visited[node] = 1;
	
	for(auto x : adj[node]) {
		if(visited[x.fi]) continue;
		sum[x.fi] = sum[node] + x.se;
		dfs(x.fi);
	}
	
}

signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i=1;i<n;++i) {
		int u,v,cost;
		cin >> u >> v >> cost;
		adj[u].push_back({v,cost});
		adj[v].push_back({u, cost});
	}
	
	for(int i=1;i<=q;++i) {
		int u,v;
		cin >> u >> v;
		memset(visited, false, sizeof visited);
		memset(sum, 0, sizeof sum);
		dfs(u);
		
		cout << sum[v] << "\n";
	}
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}