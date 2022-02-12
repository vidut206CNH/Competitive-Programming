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
const int MAXN1 = 305;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,sx,sy;
char a[MAXN1][MAXN1];
string d;
vector<pii > f[30];
int dp[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> m >> n >> sx >> sy;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			f[a[i][j] - 'a' + 1].push_back({i,j});
		}
	}
	
	cin >> d;
	
	
	int best = inf;
	
	
	for(int i = 0; i < sz(d); ++i) {
		int cur = d[i] - 'a' + 1;
		
		if(i == 0) {
			for(auto g : f[cur]) {
				int x = g.fi;
				int y = g.se;
				dp[x][y] = abs(x - sx) + abs(y - sy);
			}
		}
		else {
			for(auto g : f[cur]) {
				int x = g.fi;
				int y = g.se;
				int pre = d[i - 1] - 'a' + 1;
				if(cur == pre) {
					if(i == sz(d) - 1) {
						best = min(best, dp[x][y]);
					}
					continue;
				}
				dp[x][y] = 1e15;
				
				for(auto q : f[pre]) {
					int u = q.fi;
					int v = q.se;
					dp[x][y] = min(dp[x][y], dp[u][v] + abs(x - u) + abs(y - v));
				}
				
				if(i == sz(d) - 1) best = min(best, dp[x][y]);
			}
		}
	}
	
	cout << best;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}