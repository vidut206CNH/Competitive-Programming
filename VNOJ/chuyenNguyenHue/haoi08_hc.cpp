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
const int MAXN1 = 205;
const int MAXN2 = 1e6+5;


int n,m;
int a[MAXN1][MAXN1];
int dist[MAXN1][MAXN1];
bool P[MAXN1][MAXN1];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


struct node{
	int x,y,w;
	bool operator() (node &A, node &B) {
		return A.w > B.w;
	}
};


void dijk(int x, int y) {
	
	memset(P,0,sizeof P);
	memset(dist, 0x3f, sizeof dist);
	
	priority_queue<node, vector<node>, node > p;
	dist[x][y] = a[x][y];
	p.push({x,y,dist[x][y]});
	
	while(!p.empty()) {
		node cur = p.top();
		p.pop();
		
		if(P[cur.x][cur.y]) continue;
		P[cur.x][cur.y] = 1;
		
		for(int i=0;i<4;++i) {
			int u = cur.x + dx[i];
			int v = cur.y + dy[i];
			
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			
			if(dist[u][v] > cur.w + a[u][v]) {
				dist[u][v] = cur.w + a[u][v];
				p.push({u,v,dist[u][v]});
			}
			
		}
	}
	
}


signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}	
	
	int ans = INF;
	
	for(int i=1;i<=m;++i) {
		dijk(i,1);
		for(int j=1;j<=m;++j) {
			ans = min(ans, dist[j][n]);
		}
	}
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}