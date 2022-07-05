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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;

int m,n;
char a[MAXN1][MAXN1];
pii F[MAXN1][MAXN1];
vector<pii> D[MAXN1][MAXN1];
pii par[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1];
int cnt[MAXN1][MAXN1];
bool incycle[MAXN1][MAXN1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int res = 0,ans = 0;

void dfs(const pii & A) {
	visited[A.fi][A.se] = true;
	
	for(int k = 0; k < 4; ++k) {
		int u = A.fi + dx[k];
		int v = A.se + dy[k];
		
		if(u < 1 || u > m) continue;
		if(v < 1 || v > n) continue;
		
		if(a[u][v] != '#') continue;
		
		cnt[u][v]++;
		if(cnt[u][v] == 1) res++;	
	}
	
	ans = max(ans, res);
	
	for(auto X : D[A.fi][A.se]) {
		if(incycle[X.fi][X.se] || a[X.fi][X.se] == '.' || a[X.fi][X.se] == '#') continue;
		dfs(X);
	}
	
	
	for(int k = 0; k < 4; ++k) {
		int u = A.fi + dx[k];
		int v = A.se + dy[k];
		
		if(u < 1 || u > m) continue;
		if(v < 1 || v > n) continue;
		
		if(a[u][v] != '#') continue;
		
		cnt[u][v]--;
		if(cnt[u][v] == 0) res--;	
	}
	
}

void solve1(const vector<pii>& node) {
	auto it = node.rbegin();
	vector<pii> child;
	
	for(int i = 0; i < sz(node); ++i) {
		if(node[i].fi == it->fi && node[i].se == it->se) {
			for(int j = i; j < sz(node) - 1; ++j) {
				
				incycle[node[j].fi][node[j].se] = true;
				
				for(int k = 0; k < 4; ++k) {
					int new_u = node[j].fi + dx[k];
					int new_v = node[j].se + dy[k];
					if(new_u < 1 || new_u > m) continue;
					if(new_v < 1 || new_v > n) continue;
					if(a[new_u][new_v] != '#') continue;
					
					cnt[new_u][new_v]++;
					if(cnt[new_u][new_v] == 1) res++;
				}
				
			}
			
			for(int j = i; j < sz(node) - 1; ++j) {
				int u = node[j].fi;
				int v = node[j].se;
				
				for(auto s : D[u][v]) {
					if(incycle[s.fi][s.se] || a[s.fi][s.se] == '.' || a[s.fi][s.se] == '#') continue;
					
					child.push_back(s);
					
				}
			}
			
			break;
		}
	}
	
	ans = max(ans, res);
	
	for(auto X : child) {
		dfs(X);
	}
	
	
	// reset
	for(int i = 0; i < sz(node); ++i) {
		if(node[i].fi == it->fi && node[i].se == it->se) {
			for(int j = i; j < sz(node) - 1; ++j) {
				for(int k = 0; k < 4; ++k) {
					int new_u = node[j].fi + dx[k];
					int new_v = node[j].se + dy[k];
					if(new_u < 1 || new_u > m) continue;
					if(new_v < 1 || new_v > n) continue;
					if(a[new_u][new_v] != '#') continue;
					
					cnt[new_u][new_v]--;
					if(cnt[new_u][new_v] == 0) res--;
				}
				
			}
			break;
		}
	}	
	
}


void solve2(const vector<pii>& node) {
	pii X = *node.rbegin();
	dfs(X);
}

int main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			
			if(a[i][j] == '>' && j + 1 <= n) {
				F[i][j] = {i, j + 1};
				D[i][j + 1].push_back({i, j});
			} 
			
			if(a[i][j] == '<' && j - 1 >= 1) {
				F[i][j] = {i, j - 1};
				D[i][j - 1].push_back({i, j});
			}
			
			if(a[i][j] == '^' && i - 1 >= 1) {
				F[i][j] = {i - 1, j};
				D[i - 1][j].push_back({i, j});
			}
			
			if(a[i][j] == 'v' && i + 1 <= m) {
				F[i][j] = {i + 1, j};
				D[i + 1][j].push_back({i, j});
			}
		}
	}
	
	for(int r = 1; r <= m; ++r) {
		for(int c = 1; c <= n; ++c) {
			if(a[r][c] == '#' || a[r][c] == '.') continue;
			if(visited[r][c]) continue;
			
			int pu = 0, pv = 0, u = r, v = c;
			vector<pii> node;
			bool cyc = false;
			while(true) {
				
				node.push_back({u, v});
				par[u][v] = {pu, pv};
				
				if(visited[u][v]) {
					cyc = true;
					break;
				}
				
				visited[u][v] = true;
				pii nw = F[u][v];
				
				pu = u;
				pv = v;
				u = nw.fi;
				v = nw.se;
				if(u < 1 || u > m) break;
				if(v < 1 || v > n) break;
				if(a[u][v] == '#' || a[u][v] == '.') break;
			}
			
			if(cyc) {
				solve1(node);
			}
			
			else solve2(node);
		}
	}
	
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}