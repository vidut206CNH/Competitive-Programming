/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int MAXN1 = 83;
const int MAXN2 = 1e6+5;

struct state{
	int x,y,u,v, cost;
};


int m,n;
char a[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1][MAXN1][MAXN1];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


signed main() {
	fast_cin();
	
	cin >> m >> n;
	state start;
	pii ed;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if(a[i][j] == '*') {
				start.x = i;
				start.y = j;
			}
			if(a[i][j] == '$') {
				start.u = i;
				start.v = j;
			}
			
			if(a[i][j] == '@') {
				ed = {i,j};
			}
		}
	}
	
	deque<state> q;
	start.cost = 0;
	q.push_back(start);
	
	
	visited[start.x][start.y][start.u][start.v] = true;
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int u = q.front().u;
		int v = q.front().v;
		int cost = q.front().cost;
		
		if(u == ed.fi && v == ed.se) {
			cout << cost;
			exit(0);
		}
		
		q.pop_front();
		
		for(int i = 0; i < 4; ++i) {
			int x1 = x + dx[i];
			int y1 = y + dy[i];
			if(x1 < 1 || x1 > m) continue;
			if(y1 < 1 || y1 > n) continue;
			if(a[x1][y1] == '#') continue;
			if(x1 == u && y1 == v) {
				int u1 = u + dx[i];
				int v1 = v + dy[i];
				if(u1 < 1 || u1 > m) continue;
				if(v1 < 1 || v1 > n) continue;
				if(a[u1][v1] == '#') continue;
				if(visited[x1][y1][u1][v1] == false) {
					visited[x1][y1][u1][v1] = true;
					q.push_back({x1, y1, u1, v1, cost + 1});
				}
			}
			else if(visited[x1][y1][u][v] == false) {
				visited[x1][y1][u][v] = true;
				q.push_back({x1, y1, u, v, cost + 1});
			}
		}
	}
	
	cout << -1;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}