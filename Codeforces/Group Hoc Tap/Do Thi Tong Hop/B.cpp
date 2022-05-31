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


int m,n,k;
char a[MAXN1][MAXN1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[MAXN1][MAXN1];
vector<pii> p;

void bfs(int x, int y) {
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = true;
	
	while(!q.empty()) {
		int u = q.front().fi;
		int v = q.front().se;
		q.pop();
		p.push_back({u, v});
		
		for(int i = 0; i < 4; ++i) {
			int nu = u + dx[i];
			int nv = v + dy[i];
			
			if(nu < 1 || nu > m) continue;
			if(nv < 1 || nv > n) continue;
			
			if(a[nu][nv] == '#') continue;
			if(visited[nu][nv]) continue;
			
			q.push({nu, nv});
			visited[nu][nv] = true;
		}
		
	}
}

int main() {
	fast_cin();
	
	cin >> m >> n >> k;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	int X = 0, Y = 0;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(a[i][j] == '#') continue;
			if(X && Y) continue;
			X = i;
			Y = j;
			
		}
	}
	bfs(X, Y);
	
	reverse(p.begin(), p.end());
	for(auto x : p) {
		if(k == 0) break;
		--k;
		a[x.fi][x.se] = 'X';
	}
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cout << a[i][j];
		}
		
		cout << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}