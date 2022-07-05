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
const int MAXN1 = 3005;
const int MAXN2 = 1e6+5;

int m,n;
char a[MAXN1][MAXN1];
int dist[MAXN1][MAXN1];
vector<pii> D[30];
bool M[30];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
	fast_cin();
	
	cin >> m >> n;
	pii st,ed;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if('a' <= a[i][j] && a[i][j] <= 'z') {
				D[a[i][j] - 'a'].push_back({i, j});
			}
			
			if(a[i][j] == 'S') {
				st.fi = i;
				st.se = j;
			}
			
			if(a[i][j] == 'G') {
				ed.fi = i;
				ed.se = j;
			}
		}
	}
	
	deque<pii> dq;
	dq.push_back(st);
	memset(dist, -1, sizeof dist);
	dist[st.fi][st.se] = 0;
	int res = -1;
	while(!dq.empty()) {
		
		int x = dq.front().fi;
		int y = dq.front().se;
		
		dq.pop_front();
		
		if(x == ed.fi && y == ed.se) {
			res = dist[x][y];
			break;
		}
		
		if('a' <= a[x][y] && a[x][y] <= 'z' && !M[a[x][y] - 'a']) {
			int g = a[x][y] - 'a';
			
			for(auto X : D[g]) {
				int u = X.fi;
				int v = X.se;
				if(dist[u][v] == -1) {
					dist[u][v] = dist[x][y] + 1;
					dq.push_back({u, v});
 				}
			}
			
			M[g] = true;
		}
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			
			if(a[u][v] == '#') continue;
			if(dist[u][v] != -1) continue;
			
			dist[u][v] = dist[x][y] + 1;
			
			dq.push_back({u, v});
		}
	}
	
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}