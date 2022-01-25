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
const int MAXN1 = 115;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
int a[MAXN1][MAXN1];
bool f[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int x,int y) {
	queue<pii > q;
	visited[x][y] = 1;
	q.push({x,y});
	
	while(!q.empty()) {
		pii cur = q.front();
		q.pop();
		
		for(int i=0;i<4;++i) {
			int u = cur.fi + dx[i];
			int v = cur.se + dy[i];
			
			if(u < 1 || u > n) continue;
			if(v < 1 || v > n) continue;
			if(visited[u][v]) continue;
			if(!f[u][v]) continue;
			
			visited[u][v] = true;
			q.push({u,v});
		}
		
	}	
}


bool possible(int val) {
	
	int minn = max(0LL, max(a[1][1], a[n][n]) - val);
	int maxx = min(a[1][1], a[n][n]);
	
	
	while(minn <= maxx) {
		
		memset(visited, false, sizeof visited);
		for(int r = 1; r <= n; ++r) {
			for(int c = 1; c <= n; ++c) {
				f[r][c] = (a[r][c] >= minn && a[r][c] <= minn + val);
			}
		}
		
		bfs(1,1);
		
		if(visited[n][n]) return true;
		
		
		++minn;
	}
	
	return false;
	
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int r=1;r<=n;++r) {
		for(int c = 1; c <= n; ++c)  {
			cin >> a[r][c];
		}
	}
	
	int l = 0, r = 110,ans;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(possible(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}