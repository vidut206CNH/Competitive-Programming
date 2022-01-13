/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
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

int n,m;
int tx = 0,ty = 0,ex = 0,ey = 0;
char a[MAXN1][MAXN1];
bool visited[MAXN1][MAXN1];
//string trace[MAXN1][MAXN1];
vector< pii > E[MAXN1][MAXN1];
string res;

char dir(const int& x, const int& y, const int& u, const int& v) {
	if(x > u) return 'U';
	if(x < u) return 'D';
	if(y < v) return 'R';
	return 'L';
}

void mov(int &x, int& y,const char& c) {
	if(c == 'D') --x;
	if(c == 'U') ++x;
	if(c == 'L') ++y;
	if(c == 'R') --y;
}

void bfs(int x,int y) {
	queue<pair<pii, string> > q;
	q.push({{x,y}, ""});
	visited[x][y] = 1;
	//trace[x][y] = "";
	while(!q.empty()) {
		pii cur = q.front().fi;
		string g = q.front().se;
		q.pop();
		if(cur.fi == ex && cur.se == ey) {
			res = g;
			break;
		}
/*		db(cur.fi);
		db(cur.se);
		cerr << "\n";*/
		for(auto node : E[cur.fi][cur.se]) {
			int u = node.fi;
			int v = node.se;
			if(visited[u][v]) continue;
			
			visited[u][v] = 1;
			string tmp;
			tmp = g + dir(cur.fi,cur.se,u,v);
			q.push({{u,v},tmp});
		}
	}
}

signed main() {
	fast_cin();
	
	cin >> m >> n;
	cin.ignore();
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			if(a[i][j] == 'A') {
				tx = i;
				ty = j;
			}
			if(a[i][j] == 'B') {
				ex = i;
				ey = j;
			}
			if(a[i][j] != '#') {
				if(i > 1 && a[i-1][j] != '#') {
					E[i][j].push_back({i-1,j});
					E[i-1][j].push_back({i,j});
				}
				if(j > 1 && a[i][j-1] != '#') {
					E[i][j].push_back({i,j-1});
					E[i][j-1].push_back({i,j});
				}
			}
		}
		cin.ignore();
	}
	
	bfs(tx,ty);
	if(visited[ex][ey] == 0) {
		cout << "NO";
		exit(0);
	}
	
	
	cout << "YES\n";
	cout << sz(res) << "\n" << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}