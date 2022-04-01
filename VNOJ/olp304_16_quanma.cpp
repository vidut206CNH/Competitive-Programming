/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const long long inf = 1e18;

int n,m;
int dist[MAXN1][MAXN1];
vector<int> p(4);

int dx[] = {-1, -1, -2, -2, +1, +1, +2, +2};
int dy[] = {-2, +2, -1, +1, -2, +2, -1, +1};

signed main() {
	fast_cin();
	
	freopen("QUANMA.INP", "r", stdin);
	freopen("QUANMA.OUT", "w", stdout);
	
	cin >> m >> n;
	memset(dist, -1, sizeof dist);
	
	for(int i = 0; i < 4; ++i) {
		cin >> p[i];
	}
	
	queue<pii>q;
	
	dist[p[0]][p[1]] = 0;
	q.push({p[0], p[1]});
	
	
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;
		
		q.pop();
		
		for(int i = 0; i < 8; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			if(dist[u][v] != -1) continue;
			dist[u][v] = dist[x][y] + 1;
			
			q.push({u, v});
		}
	}
	
	cout << dist[p[2]][p[3]];
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}