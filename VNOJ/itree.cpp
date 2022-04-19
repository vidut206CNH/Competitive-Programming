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

int t,n;
vector<pii> child[MAXN1];
int dp[2][MAXN1];

void dfs(int u) {
	if(child[u].empty()) {
		dp[0][u] = 0;
		dp[1][u] = inf;
		return; 
	}
	for(auto ed : child[u]) {
		int v = ed.fi;
		int c = ed.se;
		dfs(v);
		dp[0][u] += dp[0][v];
		dp[1][u] += min(dp[0][v] + c, dp[1][v]);
	}
}


signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) child[i].clear();
		for(int i = 1; i <= n; ++i) {
			for(int k = 0; k < 2; ++k) {
				dp[k][i] = 0; 
			}
		}
		for(int i = 2; i <= n; ++i) {
			int u,c;
			cin >> u >> c;
			child[u].push_back({i,c});
		}
		
		dfs(1);
		cout << fixed << setprecision(2) << (n == 1 ? 0.00 : dp[1][1]*1.00) << "\n";
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}