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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
int dp[MAXN1][MAXN1];
int ma[MAXN1][MAXN1];

vector<int> p(4);

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < 4; ++i) cin >> p[i];
	
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dp[i][j] = inf;
			if(i == j) dp[i][j] = 0;
		}
	}
	
	int u,v,c;
	while(cin >> u >> v >> c) {
		dp[u][v] = min(dp[u][v], c);
		dp[v][u] = min(dp[v][u], c);
	}
	
	
	// floyd
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(dp[i][k] != inf && dp[k][j] != inf && dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	
	int res = inf;
	for(int node1 = 1; node1 <= n; ++node1) {
		for(int node2 = node1 + 1; node2 <= n; ++node2) {
			int best = dp[node1][node2];
			for(auto x : p) {
				best += min(dp[x][node1], dp[x][node2]);
			}
/*			db(node1);
			db(node2);
			db(best);
			cerr << "\n";*/
			res = min(res, best);
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}