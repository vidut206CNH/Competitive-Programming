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
int a[MAXN1][MAXN1];
vector< pii > adj[MAXN2];
bool visited[MAXN1][MAXN1];

void dfs(int x,int y) {
	int val = a[x][y];
	
	for(auto next : adj[val]) {
		int u = next.fi;
		int v = next.se;
		if(visited[u][v]) continue;
		visited[u][v] = true;
		dfs(u,v);
	}
}

signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			adj[i*j].push_back({i,j});
		}
	}	
	
	visited[1][1] = true;
	dfs(1,1);
	
	cout << (visited[m][n] ? "yes" : "no");
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}