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
const int MAXN1 = 1e6 + 5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int w[MAXN1];
vector<int> adj[MAXN1];
bool visited[MAXN1];
int dpmin[MAXN1];	
int dpmax[MAXN1];

void dfs(int x) {
	
	for(auto v : adj[x]) {
		if(visited[v]) continue;
		dpmin[v] = min(w[v], dpmin[x]);
		dpmax[v] = max(w[v], dpmax[x]);
		visited[v] = true;
		dfs(v);
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> w[i];	
	
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int res = 0;
	
	for(int i = 1; i <= n; ++i) {
		
		for(int v = 1; v <= n; ++v) {
			visited[v] = false;
		}
		
		dpmin[i] = w[i];
		dpmax[i] = w[i];
		
		visited[i] = true;
		dfs(i);
		
		for(int v  = i + 1; v <= n; ++v) {
			res += (dpmax[v] - dpmin[v]);
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}