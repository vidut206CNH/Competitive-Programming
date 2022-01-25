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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int m,n;
char a[MAXN1][MAXN1];
int rB,cB,rC,cC;
int dr[] = {0,0,1,-1};
int dc[] = {+1, -1, 0, 0};

int visited[MAXN1][MAXN1];

void bfs() {
	queue<pii > q;
	q.push({rC,cC});
	memset(visited, -1, sizeof visited);
	visited[rC][cC] = 0;
	
	while(!q.empty()) {
		pii cur = q.front();
		
		q.pop();
		
		for(int i=0;i<4;++i) {
			int u = cur.fi + dr[i];
			int v = cur.se + dc[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(a[u][v] == '*') continue;
			if(visited[u][v] != -1) continue;
			
			visited[u][v] = visited[cur.fi][cur.se] + 1;
			q.push({u,v});
		}
	}
	
} 

signed main() {
	fast_cin();
	
	cin >> m >> n;
	cin.ignore();
	for(int r=1;r<=m;++r) {
		for(int c = 1; c <= n; ++c) {
			cin >> a[r][c];
			if(a[r][c] == 'B') {
				rB = r;
				cB = c;
			}
			if(a[r][c] == 'C') {
				rC = r;
				cC = c;
			}
		}
		cin.ignore();
	}
	
	bfs();
	
	cout << visited[rB][cB];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}