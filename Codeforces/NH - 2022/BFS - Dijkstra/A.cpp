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
char a[MAXN1][MAXN1];
char res[MAXN1][MAXN1];
vector<pii > adj[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1];



signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	// row
	for(int i = 1; i <= m; ++i) {
		for(int l = 1; l <= n; ++l) {
			if(a[i][l] == '.') continue;
			int r = l;
			while(r <= n && a[i][r] != '.') ++r;
			--r;
			int l1 = l;
			int r1 = r;
			while(l1 < r1) {
				adj[i][l1].push_back({i, r1});
				adj[i][r1].push_back({i, l1});
				++l1;
				--r1;
			}
			l = r;
		}
	}
	
	// col
	for(int c = 1; c <= n; ++c) {
		for(int l = 1; l <= m; ++l) {
			if(a[l][c] == '.') continue;
			int r = l;
			while(r <= m && a[r][c] != '.') ++r;
			--r;
			int l1 = l;
			int r1 = r;
			while(l1 < r1) {
				adj[l1][c].push_back({r1, c});
				adj[r1][c].push_back({l1, c});
				++l1;
				--r1;
			}
			l = r;
		}
	}
	
	memset(res, 'v', sizeof res);
	queue<pii > q;
	// solve
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(visited[i][j]) continue;
			visited[i][j] = true;
			
			if(a[i][j] == '.') {
				res[i][j] = '.';
				continue;
			}
			
			q.push({i, j});
			
			vector<pii > d;
			d.push_back({i,j});
			
			// bfs
			while(!q.empty()) {
				int x = q.front().fi;
				int y = q.front().se;
				
				q.pop();
				
				for(auto next : adj[x][y]) {
					int u = next.fi;
					int v = next.se;
					if(visited[u][v]) continue;
					visited[u][v] = true;
					q.push({u,v});
					d.push_back({u,v});
				}
				
			}
			
			// results
			
			int best = inf;
			char ans;
			for(char val = '0'; val <= '9'; ++val) {
				int sum = 0;
				for(auto x : d) {
					sum += abs(val - a[x.fi][x.se]);
				}
				if(sum < best) {
					best = sum;
					ans = val;
				}
			}
			
			for(auto x : d) {
				res[x.fi][x.se] = ans;
			}
			
		}
	}
	
	for(int r = 1; r <= m; ++r) {
		for(int c = 1; c <= n; ++c) {
			cout << res[r][c];
		}
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}