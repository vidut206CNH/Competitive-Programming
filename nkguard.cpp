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
const int MAXN1 = 705;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
int a[MAXN1][MAXN1];
bool vis[MAXN1][MAXN1];
bool d[MAXN1][MAXN1];


void dfs1(int sx ,int sy) {
	for(int dx = -1; dx <= 1; ++dx) {
		for(int dy = -1; dy <= 1; ++dy) {
			int u = sx + dx;
			int v = sy + dy;
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(vis[u][v]) continue;
			if(a[u][v] != a[sx][sy]) continue;
			d[u][v] = true;
			vis[u][v] = true;
			dfs1(u, v);
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
	
	
	// mark all nodes that is not hill
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(vis[i][j]) continue;
			bool has = false;
			for(int dx = -1; dx <= 1; ++dx) {
				for(int dy = -1; dy <= 1; ++dy) {
					int u = i + dx;
					int v = j + dy;
					if(u < 1 || u > m) continue;
					if(v < 1 || v > n) continue;
					has |= (a[u][v] > a[i][j]);
				}
			}
			if(has) {
/*				db(i);
				db(j);
				cerr << "\n";*/
				d[i][j] = true;
				vis[i][j] = true;
				dfs1(i,j);
			}
		}
	}
	
	// count hill
	int res = 0;
	memset(vis, false, sizeof vis);
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(vis[i][j] || d[i][j]) continue;
			res++;
			vis[i][j] = true;
			dfs1(i, j);
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}