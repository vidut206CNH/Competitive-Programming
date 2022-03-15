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
const int MAXN1 = (1 << 13) + 5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int m,n;
char board[22][22];
int d[22][22];
int dist[15][15];
vector<pii > p;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dp[MAXN1][15];


queue<pii > q;

void bfs(int id) {
	// reset
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			d[i][j] = -1;
		}
	}
	
	
	// bfs
	q.push({p[id].fi, p[id].se});
	d[p[id].fi][p[id].se] = 0;
	
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;
		
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(board[u][v] == 'x')	continue;
			if(d[u][v] == -1) {
				d[u][v] = d[x][y] + 1;
				q.push({u,v});
 			}	
		}
	}
	
	for(int i = 0; i < sz(p); ++i) {
		int x = p[i].fi;
		int y = p[i].se;
		dist[id][i] = d[x][y];
	}
	
}

void solve() {
	
	// reset
	p.clear();
	memset(dist, -1, sizeof dist);
	
	
	// init
	pii robot;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> board[i][j];
			if(board[i][j] == 'o') {
				robot = {i,j};
			}
			if(board[i][j] == '*') {
				p.push_back({i,j});
			}
		}
	}
	
	p.push_back({robot});
	reverse(p.begin(), p.end());
	
	// bfs
	for(int i = 0; i < sz(p); ++i) {
		bfs(i);
	}
	
	
	// dp bitmask
	int res = inf;
	
	for(int i = 0; i < (1 << sz(p)); ++i) {
		for(int j = 0; j < sz(p); ++j) {
			dp[i][j] = inf;
		}
	}
	
	for(int j = 1; j < sz(p); ++j) {
		if(dist[0][j] == -1) continue;
		dp[(1 << j)|1][j] = dist[0][j];
	}
	int lim = sz(p);
	
	for(int mask = 0; mask < (1 << lim); ++mask) {
		for(int last = 0; last < lim; ++last) {
			if(!(mask >> last & 1)) continue;
			
			for(int last1 = 0; last1 < lim; ++last1) {
				if(!(mask >> last1 & 1)) continue;
				if(last1 == last) continue;
				int mask1 = mask&(~(1 << last));
				
				if(dist[last1][last] == -1) continue;
				
				if(dp[mask1][last1] == inf) continue;
				
				dp[mask][last] = min(dp[mask][last], dp[mask1][last1] + dist[last1][last]);
			}
			if(mask == (1 << lim) - 1) res = min(res, dp[mask][last]);			
		}
	}
	if(sz(p) == 1) cout << 0;
	else cout << (res == inf ? -1 : res);
}




signed main() {
	fast_cin();
	
	while(cin >> n >> m) {
		if(m == 0 && n == 0) break;
		solve();
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}