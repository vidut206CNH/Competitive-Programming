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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int m,n;
int a[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1];
bool p[MAXN1][MAXN1];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


bool check(int val, int x, int y) {
	queue<pii> q;
	
	for(int i = 1;i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			p[i][j] = (a[i][j] < val);
			visited[i][j] = false;
		}
	}
	
	q.push({x,y});
	visited[x][y] = true;
	
	while(!q.empty()) {
		int u = q.front().fi;
		int v = q.front().se;
		
		q.pop();
		
		if(u == 1 || u == m) return false;
		if(v == 1 || v == n) return false;
		
		for(int i = 0; i < 4; ++i) {
			int u1 = u + dx[i];
			int v1 = v + dy[i];
			if(u1 < 1 || u1 > m) continue;
			if(v1 < 1 || v1 > n) continue;
			if(!p[u1][v1]) continue;
			if(visited[u1][v1]) continue;
			if(u1 == 1 || u1 == m) return false;
			if(v1 == 1 || v1 == n) return false;
			
			visited[u1][v1] = true;
			
			q.push({u1, v1});
 		}
	}
	return true;
}


signed main() {
	fast_cin();
	
	
	cin >> m >> n;
	int maxx = 0;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			maxx = max(maxx, a[i][j]);
		}
	}
	
	int res = 0;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			int low = a[i][j], high = maxx, best = low;
			
			
			while(low <= high) {
				int mid = (low + high) >> 1;
				
				if(check(mid, i, j)) {
					best = mid;
					low = mid + 1;
				} else high = mid - 1;
			}
			
			res += (best - a[i][j]);
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}