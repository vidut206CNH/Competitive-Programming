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
const int MAXN1 = 303;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
string s;
char a[MAXN1][MAXN1];
int dist[MAXN1][MAXN1][MAXN1];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct node{
	int pos, x, y;
};

signed main() {
	fast_cin();
	
	memset(dist, -1, sizeof dist);
	
	cin >> m >> n;
	int sx,sy;
	cin >> sx >> sy;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	cin >> s;
	int ssize = sz(s);
	s = '0' + s;
	
	deque< node > q;
	q.push_back({0, sx, sy});
	dist[0][sx][sy] = 0;
	
	while(!q.empty()) {
		
		int c = q.front().pos;
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop_front();
		
/*		db(c);
		db(x);
		db(y);
		cerr << "\n";*/
		
		
		if(dist[c + 1][x][y] == -1 && a[x][y] == s[c + 1]) {
			dist[c + 1][x][y] = dist[c][x][y];
			if(c + 1 == ssize) {
				cout << dist[c + 1][x][y];
				exit(0);
			}
			q.push_front({c + 1, x, y});
		}
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			if(u < 1 || u > m ) continue;
			if(v < 1 || v > n ) continue;
			
			if(dist[c][u][v] == -1) {
				dist[c][u][v] = dist[c][x][y] + 1;
				q.push_back({c, u, v});
			}
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}