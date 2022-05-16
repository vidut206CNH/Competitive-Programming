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
int p[MAXN1];
vector<int> adj[MAXN1];
int dp[MAXN1];
bool ok = true;


void dfs(int u, int par) {
	if(sz(adj[u]) == 1) return;
	
	vector<int> d;
	int maxC = 0, sum = 0;
	
	for(auto v : adj[u]) {
		if(v == par) continue;
		dfs(v, u);
		
		d.push_back(dp[v]);
		sum += dp[v];
	}
	
	int c = sum - p[u];
	sort(d.begin(), d.end());
	if(d[sz(d) - 1]*2 <= sum) {
		maxC = sum/2;
	}
	else {
		maxC = sum - d[sz(d) - 1];
	}
	
	ok &= (c <= maxC && c >= 0);
	dp[u] = sum - 2*c;
/*	db(dp[u]);
	db(u);
	cerr << "\n";*/
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	
	for(int i = 2; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	if(n == 2) {
		cout << (p[1] == 1 && p[2] == 1 ? "YES\n" : "NO\n");
		return 0;
	}
	
	int root = -1;
	for(int i = 1; i <= n; ++i) {
		if(sz(adj[i]) == 1) {
			dp[i] = p[i];
		}
		else root = i;
	}
	
	dfs(root, -1);
	db(ok);
	cout << (ok && dp[root] == 0 ? "YES\n" : "NO\n");
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}