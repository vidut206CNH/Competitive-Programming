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
const int MAXN1 = 3005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


struct state{
	int x,y,val;
};

struct comp{
	bool operator() (const state &A, const state &B) {
		return A.val > B.val;
	}
};

vector< state > a[MAXN1][20];
int dist[MAXN1][20];
bool P[MAXN1][20];

int m,n;


signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 1; i <= 2*m + 1; ++i) {
		if(i&1) {
			for(int j = 1; j <= n; ++j) {
				int x;
				cin >> x;
				int r = (i + 1)/2;
				a[r][j].push_back({r + 1, j, x});
				a[r + 1][j].push_back({r, j, x});
			}
		}
		else {
			for(int j = 1; j < n; ++j) {
				int x;
				cin >> x;
				int r = i/2 + 1;
				a[r][j].push_back({r, j + 1, x});
				a[r][j + 1].push_back({r, j, x});
			}
		}
	}
	
	
	// dijkstra
	memset(dist, -1, sizeof dist);
	
	priority_queue<state, vector<state >, comp > pq;
	for(int i = 1; i <= n; ++i) {
		dist[1][i] = 0;
		pq.push({1, i, 0});
	}
	
	while(!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int val = pq.top().val;
		pq.pop();
		
/*		db(x);
		db(y);
		db(val);
		cerr << "\n";*/
		
		if(P[x][y]) continue;
		P[x][y] = true;
		
		for(auto next : a[x][y]) {
			int u = next.x;
			int v = next.y;
			int cost = next.val;
			if(dist[u][v] == -1 || (dist[u][v] > val + cost)) {
				dist[u][v] = cost + val;
				pq.push({u, v, dist[u][v]});
			}
		}
	}
	
	cout << dist[m + 1][n];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}