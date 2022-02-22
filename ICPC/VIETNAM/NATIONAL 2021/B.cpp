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
const int MAXN1 = 55;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
char a[MAXN1][MAXN1];
vector<pii > adj[MAXN1][MAXN1];
int cnt[MAXN1];
bool visited[MAXN1][MAXN1];


void dfs(int x, int y) {
	visited[x][y] = true;
	cnt[(int)a[x][y] - 'A' + 1]++;
	
	for(auto next : adj[x][y]) {
		int u = next.fi;
		int v = next.se;
		if(visited[u][v] == true) continue;
		dfs(u,v);
	}
	
}

// ABCDEFGHIJKLMNOPQRSTUVWXYZ


signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int r = 1; r <= m; ++r) {
		for(int c = 1; c <= n; ++c) {
			cin >> a[r][c];
			// 
			adj[r][c].push_back({m - r + 1, c});
			//
			adj[r][c].push_back({r, n - c + 1});
			
/*			db(r);
			db(c);
			db(m - r + 1);
			db(c);
			db(r);
			db(n - c + 1);
			cerr << "\n";*/
			
		}
	}
	
	
	// BFS
	
	int res = 0;
	for(int r = 1; r <= m; ++r) {
		for(int c = 1; c <= n; ++c) {
			if(visited[r][c]) continue;
			memset(cnt, 0, sizeof cnt);
			dfs(r, c);
			int best = inf;
			
			for(int val = 1; val <= 26; ++val) {
				int sum = 0;
				for(int k = 1; k <= 26; ++k) {
					sum += min({abs(val - k), abs(26 + val - k), abs(26 + k - val)})*cnt[k];
				}
				best = min(best, sum);
			}
			
			res += best;
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}