/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 1e3 + 3;
const int MAXN2 = 6e6+3;


struct state{
	int x, y, times;
};

int m,n,k;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int dist[MAXN1][MAXN1][5];
int a[MAXN1][MAXN1];
bool visited[MAXN2];
bool ok[MAXN1][MAXN1];

int main() {
	fast_cin();
	
	cin >> m >> n >> k;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}	
	
	memset(dist, -1, sizeof dist);
	deque<state> q;
	
	int p,Q;
	cin >> p >> Q;
	for(int i = 1; i <= p; ++i) {
		int x,y;
		cin >> x >> y;
		if(a[x][y]) {
			q.push_back({x, y, 0});
			dist[x][y][0] = 0;
		}	
	}
	
	for(int i = 1; i <= Q; ++i) {
		int x,y;
		cin >> x >> y;
		ok[x][y] = (a[x][y]);
	}
	
	int res = -1;
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int times = q.front().times;
		int val = dist[x][y][times];
		
		if(ok[x][y]) {
			res = val;
			break;
		}
		
		q.pop_front();
		
		if(times < k && visited[a[x][y]] == false) {
			for(int r = 1; r <= min(m, n) && r*r <= a[x][y]; ++r) {
				if(a[x][y]%r) continue;
				
				int c = a[x][y]/r;
				
				if(r <= m && c <= n && a[r][c] != 0 && dist[r][c][times + 1] == -1) {
					dist[r][c][times + 1] = val + 1;
					q.push_back({r, c, times + 1});
				}
				
				int r1 = c, c1 = r;
				
				if(r1 <= m && c1 <= n && a[r1][c1] != 0 && dist[r1][c1][times + 1] == -1) {
					dist[r1][c1][times + 1] = val + 1;
					q.push_back({r1, c1, times + 1});
				}
				
			}
			
			visited[a[x][y]] = true;
 		}
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(dist[u][v][times] != -1) continue;
			if(a[u][v] == 0) continue;
			
			dist[u][v][times] = val + 1;
			q.push_back({u, v, times});
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
