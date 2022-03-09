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


struct data{
	int type;
	int x, y;
};

int m,n;
vector<int> p(4);
char a[MAXN1][MAXN1];
int dist[3][MAXN1][MAXN1];
queue<data> q;
int dx0[] = {-2, 0, 1, 0};
int dy0[] = {0, -2, 0, 1};

// 0: 1x1
// 1: 1x2
// 2: 2x1



bool check(int x, int y, int u, int v) {
	if(x < 1 || u < 1 || y < 1 || v < 1) return false;
	if(x > m || u > m) return false;
	if(y > n || v > n) return false;
	
	bool good = true;
	for(int i = x; i <= u; ++i) {
		for(int j = y; j <= v; ++j) {
			good &= (a[i][j] != '*');
		}
	}
	
	return good;
}



void calc(int type, int x, int y, int u, int v,const int &cost) {
	if(check(x, y, u, v) == false) return;
	if(dist[type][x][y] != -1) return;
	dist[type][x][y] = cost + 1;
	q.push({type, x, y});
}




signed main() {
	fast_cin();
	int t;
	cin >> t;
	while(t--) {
		cin >> m >> n;
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		
		for(int i = 0; i < 4; ++i) cin >> p[i];
		
		
		// init
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				for(int type = 0; type < 3; ++type) {
					dist[type][i][j] = -1;
				}
			}
		}
		
		
		// BFS
		q.push({0, p[0], p[1]});
		dist[0][p[0]][p[1]] = 0;
		
		while(!q.empty()) {
			int type = q.front().type;
			int x = q.front().x;
			int y = q.front().y;
			int cost = dist[type][x][y];
			q.pop();
			
			if(type == 0) {
				calc(1, x, y - 2, x, y - 1, cost);
				calc(1, x, y + 1, x, y + 2, cost);
				calc(2, x - 2, y, x - 1, y, cost);
				calc(2, x + 1, y, x + 2, y, cost);
			}
			if(type == 1) {
				calc(1, x + 1, y, x + 1, y + 1, cost);
				calc(1, x - 1, y, x - 1, y + 1, cost);
				calc(0, x, y - 1, x, y - 1, cost);
				calc(0, x, y + 2, x, y + 2, cost);
			}
			if(type == 2) {
				calc(2, x, y - 1, x + 1, y - 1, cost);
				calc(2, x, y + 1, x + 1, y + 1, cost);
				calc(0, x - 1, y, x - 1, y, cost);
				calc(0, x + 2, y, x + 2, y, cost);
			}
		}
		
		cout << dist[0][p[2]][p[3]] << "\n";
	

	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}