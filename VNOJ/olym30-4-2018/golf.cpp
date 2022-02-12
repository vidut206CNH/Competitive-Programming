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

int m,n;
int a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[MAXN1][MAXN1];


int bfs(int x, int y, int cost) {
	queue<pii > q;
	
	q.push({x,y});
	int cnt = 0;
	
	
	while(!q.empty()) {
		int u = q.front().fi;
		int v = q.front().se;
		
		cnt += f[u][v];
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int uu = u + dx[i];
			int vv = v + dy[i];
			
			if(uu < 1 || uu > m) continue;
			if(vv < 1 || vv > n) continue;
			
			if(visited[uu][vv]) continue;
			
			if(abs(a[u][v] - a[uu][vv]) > cost) continue;
			
			visited[uu][vv] = true;
			q.push({uu,vv});
		}
		
	}
	
	return cnt;
}

signed main() {
	fast_cin();
	
	freopen("golf.inp", "r", stdin);
	freopen("golf.out", "w", stdout);
	
	
	cin >> m >> n;
	int fixx = 0;
	
	for(int i=1;i<= m;++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	int stx = -1, sty = -1;
	
	for(int i=1;i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> f[i][j];
			if(f[i][j]) {
				stx = i;
				sty = j;
			}
			fixx += f[i][j];
		}
	}
	
	if(fixx == 0) {
		cout << 0;
		exit(0);
	}
	
	int low = 0, high = 1e9,res = 1e9 + 7;
	
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		
		memset(visited, false, sizeof visited);
		visited[stx][sty] = true;
		
		int g = bfs(stx, sty, mid);
		if(g == fixx) {
			res = mid;
			high = mid - 1;
		} else low = mid + 1;
		
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}