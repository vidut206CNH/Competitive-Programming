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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


struct node{
	bool type;
	int x;
	int y;
};


int m,n;
int res = 0;
vector<pii > adj[2][MAXN1][MAXN1];
int dist[2][MAXN1][MAXN1];
// 0: white
// 1: black

queue<node> q;
bool visited[2][MAXN1][MAXN1];


void bfs(bool d, int sx, int sy, int ex, int ey) {
	memset(dist, -1, sizeof dist);
	
	dist[d][sx][sy] = 0;
	q.push({d, sx, sy});
	
	while(!q.empty()) {
		int dir = q.front().type;
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
				
		for(auto next : adj[!dir][x][y]) {
			int u = next.fi;
			int v = next.se;
			if(dist[!dir][u][v] == -1) {
				dist[!dir][u][v] = dist[dir][x][y] + 1;
				q.push({!dir, u, v});
			}
		}
	}
	
	for(int dir = 0; dir < 2; ++dir) {
		if(dist[dir][ex][ey] != -1) res = min(res, dist[dir][ex][ey]);
	}
}


signed main() {
	fast_cin();
	
	cin >> n >> m;
	
	vector<int> p(4);
	for(int i = 0; i < 4; ++i) cin >> p[i];
	
	for(int i = 0; i < 2*m + 1; i++) {
		string s;
		cin >> s;
		if(i&1) {
			for(int id = 0; id < 2*n + 1; ++id) {
				if(s[id] == 'n') continue;
				bool d = (s[id] == 'w' ? 0 : 1);
				if(id&1) {
					int y = id/2;
					int x = i/2;
					adj[d][x][y + 1].push_back({x + 1, y});
					adj[d][x + 1][y].push_back({x, y + 1});
				}
				else {
					int x = i/2;
					int y = id/2;
					adj[d][x][y].push_back({x + 1, y});
					adj[d][x + 1][y].push_back({x, y});
				}
			}
		}
		
		else {
			for(int c = 0; c < n; c++) {
				if(s[c] == 'n') continue;
				bool d = (s[c] == 'w' ? 0 : 1);
				adj[d][i/2][c].push_back({i/2, c + 1});
				adj[d][i/2][c + 1].push_back({i/2, c});
			}
		}
	}
	
	res = inf;
	bfs(false, p[1], p[0], p[3], p[2]);
	bfs(true, p[1], p[0], p[3], p[2]);
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}