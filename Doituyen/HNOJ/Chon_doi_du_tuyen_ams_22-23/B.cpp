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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
char a[105][105];
bool vis[105][105];
bool bad = false;
int cnt = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y) {
	
	
	queue<pii> q;
	q.push({x, y});
	vis[x][y] = true;
	
	while(!q.empty()) {
		
		cnt++;
		int s = q.front().fi;
		int t = q.front().se;
		bad |= (s == 1 || s == m);
		bad |= (t == 1 || t == n);
		q.pop();
		
		
		for(int i = 0; i < 4; ++i) {
			int u = s + dx[i];
			int v = t + dy[i];
			
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(a[u][v] == '1') continue;
			if(vis[u][v]) continue;
			
			vis[u][v] = true;
			q.push({u,v});
		}
	}
}

signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	int res = 0;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(vis[i][j] == false && a[i][j] == '0') {
				cnt = 0;
				bad = false;
				bfs(i,j);
/*				db(i);
				db(j);
				db(bad);
				cerr << "\n";*/
				if(!bad) res += cnt;
			}
		}
	}
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}