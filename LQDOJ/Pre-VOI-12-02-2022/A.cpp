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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
bool a[MAXN1][MAXN1];
int h[MAXN1][MAXN1];
pii par[MAXN1][MAXN1];
pii P[MAXN1][MAXN1][20];


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void bfs(int x, int y) {

	queue<pii > qu;
	qu.push({x,y});
	
	h[x][y] = 1;
	
	while(!qu.empty()) {
		int cx = qu.front().fi;
		int cy = qu.front().se;
		
		qu.pop();
		
		for(int i = 0; i < 4; ++i) {
			int u = cx + dx[i];
			int v = cy + dy[i];
			
			if(u < 1 || u > n) continue;
			if(v < 1 || v > n) continue;
			
			if(a[u][v]) continue;
			if(h[u][v]) continue;
			
			h[u][v] = h[cx][cy] + 1;
			qu.push({u, v});
		}
		
	}
	
}


void sub1() {
	while(q--) {
		
		int type;
		cin >> type;
		if(type == 1) {
			int u,v;
			cin >> u >> v;
			a[u][v] = 1;
		}
		
		else {
			int u,v,x,y;
			cin >> u >> v >> x >> y;
			memset(h, 0, sizeof h);
			bfs(u,v);
			if(h[x][y]) {
				cout << h[x][y] << "\n";
			} else cout << "-1\n";
		}
	}
}


void dfs(int px, int py, int x, int y) {
/*	db(x);
	db(y);
	db(h[x][y]);
	cerr << "\n";*/
	for(int i = 0; i < 4; ++i) {
		int u = x + dx[i];
		int v = y + dy[i];
		
		if(u < 1 || u > n) continue;
		if(v < 1 || v > n) continue;
		if(a[u][v]) continue;
		if(px == u && py == v) continue;
		
		h[u][v] = h[x][y] + 1;
		par[u][v] = {x, y};
		
		dfs(x, y, u, v);
	}
}



pii lca(int xu, int yu,int xv, int yv) {
	if(h[xu][yu] < h[xv][yv]) {
		swap(xu, xv);
		swap(yu, yv);
	}
	
	for(int i = 19; i >= 0; --i) {
		if(h[xu][yu]  - (1 << i) >= h[xv][yv]) {
			int tx = P[xu][yu][i].fi;
			int ty = P[xu][yu][i].se;
			xu = tx;
			yu = ty;
		}
	}
/*	db(h[xu][yu]);
	db(xu);
	db(yu);
	cerr << '\n';*/
	if(xu == xv && yu == yv) {
		return {xu, yu};
	}
	
	if(P[xu][yu][0].fi == 0) {
		return {xu, yu};
	}
	
	for(int i = 19; i >= 0; --i) {
		if(P[xu][yu][i].fi != 0 && P[xv][yv][i] != P[xu][yu][i]) {
			int tx,ty;
			tx = P[xu][yu][i].fi;
			ty = P[xu][yu][i].se;
			xu = tx;
			yu = ty;
			
			tx = P[xv][yv][i].fi;
			ty = P[xv][yv][i].se;
			xv = tx;
			yv = ty;		
		}
	}
/*	db(xu);
	db(yu);*/
	return par[xu][yu];
}


void sub2() {
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; (1 << k) < n*n; ++k) P[i][j][k] = {0,0};
		}
	}
	
	
	bool dfs_ok = false;
	memset(h, -1, sizeof h);
	
	for(int i = 1;i <= n; ++i) {
		if(dfs_ok) break;
		for(int j = 1; j <= n; ++j) {
			if(a[i][j]) continue;
			h[i][j] = 0;
			dfs(0, 0, i, j);
			dfs_ok = true;
			break;
		}
	}
	
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			P[i][j][0] = par[i][j];
		}
	}
	
	for(int k = 1; (1 << k) < n*n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(P[i][j][k - 1].fi != 0) {
					int u = P[i][j][k - 1].fi;
					int v = P[i][j][k - 1].se;
					P[i][j][k] = P[u][v][k - 1];
					
/*					db(i);
					db(j);
					db(k);
					db(P[i][j][k].fi);
					db(P[i][j][k].se);
					cerr << "\n";*/
				}
			}
		}
	}
	
	while(q--) {
		int type;
		cin >> type;
		int u,v,s,t;
		cin >> u >> v >> s >> t;
		if(h[u][v] == -1 || h[s][t] == -1) {
			cout << "-1\n";
			continue;
		}
		pii d = lca(u, v, s, t);
		
		cout << h[u][v] + h[s][t] - 2*h[d.fi][d.se] + 1 << "\n";
	}
	
	
	
}



signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	
/*	if(n <= 100 && q <= 100) {
		sub1();
	}*/
	
	sub2();
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}