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

int n;
vector<int> adj[MAXN1];
int res[MAXN1];
int sum = 0;

void dfs(int u, int p) {
	
	for(auto v : adj[u]) {
		if(v == p) continue;
		
		dfs(v, u);
	}
	
	if(res[u] == u) {
		sum += 2;
		if(p != 0) swap(res[u], res[p]);
		else swap(res[u], res[adj[u].back()]);
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;++i) res[i] = i;
	dfs(1, 0);
	
	cout << sum << "\n";
	for(int i=1;i<=n;++i) cout << res[i] << " ";
		
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}