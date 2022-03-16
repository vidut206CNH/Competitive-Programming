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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;
vector<int> adj[MAXN1];
int color[MAXN1];
string s;
bool visited[MAXN1];
bool bad = false;

int dp[30][MAXN1];
vector<int> topo;

void dfs(int x) {
	color[x] = 1;
	for(auto v : adj[x]) {
		if(color[v] == 0) {
			dfs(v);
		}
		if(color[v] == 1) {
			bad = true;
			return;
		}
	}
	topo.push_back(x);
	color[x] = 2;
}



signed main() {
	fast_cin();
	
	cin >> n >> m;
	cin >> s;
	s = '0' + s;
	
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	// check cycle
	memset(color, 0, sizeof color);
	for(int i = 1; i <= n; ++i) {
		if(color[i] == 0) dfs(i);
	}
	
	if(bad) return cout << -1, 0;

	int res = 0;
	
	reverse(topo.begin(), topo.end());
	
	for(int c = 1; c <= 26; ++c) {
		for(auto x : topo) {
			dp[c][x] += (s[x] == c + 'a' - 1);
			res = max(res, dp[c][x]);
			for(auto v : adj[x]) {
				dp[c][v] = max(dp[c][v], dp[c][x]);
			}
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}