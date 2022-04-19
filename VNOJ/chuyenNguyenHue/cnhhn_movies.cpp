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
const int MAXN1 = 2e4 + 5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,s,f;
int dp[2][MAXN1];
vector<int> child[MAXN1];
bool visited[MAXN1];
bool par[MAXN1];

void dfs(int u) {
	dp[0][u] = s;
	dp[1][u] = f;
	
	for(int v : child[u]) {
		dfs(v);
		
		dp[0][u] += min(dp[0][v], dp[1][v]);
		dp[1][u] += min(dp[1][v], dp[0][v] - s);
		
	}
	
}

signed main() {
	fast_cin();
	
	
	cin >> n >> m >> s >> f;
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		child[u].push_back(v);
		par[v] = true;
	}
	
	int res = 0;
	
	for(int i = 1; i <= n; ++i) {
		if(!par[i]) {
			dfs(i);
			res += min(dp[0][1], dp[1][1]);
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}