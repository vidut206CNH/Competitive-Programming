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

int m,n;
int sx,sy;
char a[MAXN1][MAXN1];
queue<pii > q;
int dist[MAXN1][MAXN1];
int path[MAXN1][MAXN1];
bool ok = false;
bool found = false;
vector<int> res;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string pre = "RLDU";

void bfs() {
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;
		
/*		db(x);
		db(y);
		cerr << "\n";*/
		q.pop();
		
		
		if(ok && (x == 1 || y == 1 || x == m || y == n)) {	
			cout << "YES\n";
			while(dist[x][y] != 0) {
				int d = path[x][y];
				res.push_back(d);
				
				x -= dx[d];
				y -= dy[d];
						
			}
			reverse(res.begin(), res.end());
			cout << res.size() << "\n";
			for(auto id : res) 	cout << pre[id];
			found = true;
			break;
		}
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(a[u][v] == '#') continue;
			
			if(dist[u][v] > dist[x][y] + 1) {
				dist[u][v] = dist[x][y] + 1;
				path[u][v] = i;
				q.push({u,v});
			}
		}
	}
}


signed main() {
	fast_cin();
	
	
	cin >> m >> n;
	
	
	memset(path, -1, sizeof path);
	memset(dist, 0x3f, sizeof dist);
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if(a[i][j] == 'M') {
				q.push({i,j});
				dist[i][j] = 0;
			}
			
			if(a[i][j] == 'A') {
				sx = i;
				sy = j;
			}
		}
	}
	
	bfs();
	ok = true;
//	cerr << "\n";
	q.push({sx,sy});
	dist[sx][sy] = 0;
	bfs();
	
	if(!found) cout << "NO";	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}