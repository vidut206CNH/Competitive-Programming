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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int m,n;
vector<pii > mp[MAXN2];
bool ok[MAXN2];
int a[MAXN1][MAXN1];
int vis[MAXN1][MAXN1];
int start_x, start_y, end_x, end_y;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<int> p;
map<int,int> d;


bool chk(const pii& A, const pii& B) {
	int m1 = abs(A.fi - end_x) + abs(A.se - end_y);
	int m2 = abs(B.fi - end_x) + abs(A.se - end_y);
	return m1 < m2;
}

signed main() {
	fast_cin();
	cin >> m >> n;
	cin >> start_x >> start_y >> end_x >> end_y;
	bool bad = 0;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			if(a[i][j] == 0) bad = 1;
			d[a[i][j]] = 1;
		}
	}	
	
	int id = 1;
	if(bad) id = 0;
	for(auto &e : d) {
		//cout << e.fi << " ";
		e.se = id;
		++id;
	}
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			a[i][j] = d[a[i][j]];
			mp[a[i][j]].push_back({i,j});
		}
	}
	
	queue<pii > q;
	q.push({start_x, start_y,});
	vis[start_x][start_y] = 1;
	
	while(!q.empty()) {
		pii cur = q.front();
		
		if(cur.fi == end_x && cur.se == end_y) break;
		
		q.pop();
		
		
		for(int i=0;i < 4;++i) {
			int u = cur.fi + dx[i];
			int v= cur.se + dy[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(vis[u][v]) continue;
			if(a[u][v] == 0) continue;
			
			vis[u][v] = vis[cur.fi][cur.se] + 1;
			q.push({u,v});
		}
		
		if(ok[a[cur.fi][cur.se]]) continue;
		ok[a[cur.fi][cur.se]] = 1;
		
		for(auto x : mp[a[cur.fi][cur.se]]) {
			
			if(x.fi == cur.fi && x.se == cur.se) continue;
			if(vis[x.fi][x.se]) continue;
			if(chk(cur, x)) continue;	
			//cout << x.fi << " " << x.se << "\n";
 			vis[x.fi][x.se] = vis[cur.fi][cur.se] + 1;
			q.push(x);

		}
		
		
	}
	
	cout << vis[end_x][end_y] - 1;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}