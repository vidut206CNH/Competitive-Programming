/* 
	link problem: https://oj.vnoi.info/problem/haoi12_robot
	Author : vidut_206_CNH
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int m,n,stx,sty,edx,edy;
char a[205][205];
pair<int,pii> trace[205][205];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool chk(int x,int y, int &m,int &n) {
	return (0 < x && x <= m && 0 < y && y <= n);
}

void dfs(int x,int y) {
	queue< pii > q;
	trace[x][y] = {1,{x,y}};
	q.push({x,y});
	while(!q.empty()) {
		int u = q.front().fi;
		int v = q.front().se;
		q.pop();
		for(int i=0;i<4;++i) {
			int tx = u + dx[i];
			int ty = v + dy[i];
			if(chk(tx,ty,m,n) && !trace[tx][ty].fi && a[tx][ty] != '1') {
				q.push({tx,ty});
				trace[tx][ty] = {trace[u][v].fi+1,{u,v}};
				//cout << u << ' ' << v << ' ' << tx << ' ' << ty << '\n';
			}
		}
	}
}

void solve() {
	cin >> m >> n;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			if(a[i][j] == '2') {
				stx = i;
				sty = j;
			}
			if(a[i][j] == '3') {
				edx = i;
				edy = j;
			}
		}
	}
	dfs(edx,edy);
	int ti = trace[stx][sty].fi;
	cout << ti << '\n';
	int u = stx,v = sty;
	while(ti) {
		cout << u << ' ' << v << '\n';
		pii tmp = trace[u][v].se;
		u = tmp.fi;
		v = tmp.se;
		ti--;
	}
	//cout << trace[1][3].se.fi << ' ' << trace[1][3].se.se;
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}