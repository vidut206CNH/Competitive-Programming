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


int n,k;
vector<int> adj[MAXN1];
vector<int> color(MAXN1,0);
int dp[4][MAXN1];
bool visited[MAXN1];

void dfs(int cur=1, int par = 0) {
	if(visited[cur]) return;


	visited[cur] = 1;


	bool good = 0;

	for(int c = 1; c <= 3; ++c) {
		if(c != color[cur] && color[cur]) continue;
		int prod = 1;
		
		for(auto x : adj[cur]) {
			if(x == par) continue;
			
			dfs(x, cur);
			
			good = 1;
			
			int sum = 0;
			for(int d = 1; d <= 3; ++d) {
				if(c == d) continue;
				sum = (sum + dp[d][x])%MOD;
			}
			
			prod = prod*sum%MOD;
			
		}
		
		dp[c][cur] = prod;
		
	}
	
	if(!good) {
		for(int c = 1; c <= 3;++c) {
			if(c == color[cur] || color[cur] == 0) {
				dp[c][cur] = 1;
				//cerr << c << " " << cur << "\n";
			}
		}
	}

/*	for(int c=1;c<=3;++c) {
		db(c);
		db(cur);
		cerr << dp[c][cur] << "\n";
	}
	cerr << "\n";*/

}

signed main() {
	fast_cin();
/*	
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	*/
	
	cin >> n >> k;
	
	for(int i=1;i<n;++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=1;i<=k;++i) {
		int u,c;
		cin >> u >> c;
		color[u] = c;
	}
	
	dfs();
	
	int ans = 0;
	for(int c=1;c<=3;++c) {
		ans = (ans + dp[c][1])%MOD;
	}
	
	cout << ans;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}