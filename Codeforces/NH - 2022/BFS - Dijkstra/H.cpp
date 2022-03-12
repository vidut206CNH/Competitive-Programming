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

struct state{
	int id;
	int x;
	int y;
};


int m,n,k;
char a[MAXN1][MAXN1];
pii p[MAXN1];
pii start, ed;
int dp[MAXN1][MAXN1][MAXN1];
queue<state> q;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

signed main() {
	fast_cin();
	
	cin >> m >> n >> k;
	for(int r = 1; r <= m; ++r) {
		for(int c = 1;  c <= n; ++c) {
			cin >> a[r][c];
			if(a[r][c] == 'S') {
				start = {r, c};
			}
			if(a[r][c] == 'F') {
				ed = {r,c};
			}
		}
	}	
	
	for(int i = 1; i <= k; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	
	
	memset(dp, -1, sizeof dp);
	
	dp[0][start.fi][start.se] = 0;
	q.push({0, start.fi, start.se});
	
	while(!q.empty()) {
		int id = q.front().id;
		int x = q.front().x;
		int y = q.front().y;
		
		
		q.pop();
		
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(u == p[id + 1].fi && v == p[id + 1].se && dp[id + 1][x][y] == -1) {
				dp[id + 1][x][y] = dp[id][x][y];
				q.push({id + 1, x, y});
			}
		}
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(a[u][v] == '#') continue;
			if(dp[id][u][v] != -1) continue;
			dp[id][u][v] = dp[id][x][y] + 1;
			q.push({id, u, v}); 
		}
		
	}
	
	cout << dp[k][ed.fi][ed.se];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}