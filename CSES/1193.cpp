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
int trace[MAXN1][MAXN1];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string p = "RLDU";

signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 1; i <= m;++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if(a[i][j] == 'A') {
				sx = i;
				sy = j;
			}
		}
	}	
	
	vector<int> path;
	memset(trace, -1, sizeof trace);
	queue<pii > q;
	q.push({sx, sy});
	
	while(!q.empty()) {
		
		int x = q.front().fi;
		int y = q.front().se;
		
		q.pop();
		
		
		if(a[x][y] == 'B') {
			
			while(trace[x][y] != -1) {
				int pre = trace[x][y];
				path.push_back(pre);
				
				x -= dx[pre];
				y -= dy[pre];
			}
			reverse(path.begin(), path.end());
			break;
		}
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(a[u][v] == '#') continue;
			if(trace[u][v] == -1 && (u != sx || v != sy)) {
				trace[u][v] = i;
				q.push({u,v});
			}
		}
		
	}
	
	if(sz(path)) {
		cout << "YES\n";
		cout << path.size() << "\n";
		for(auto x : path) cout << p[x];
	} else cout << "NO";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}