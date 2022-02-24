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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
int c[MAXN1][MAXN1];
int dist[3][MAXN1][MAXN1];
bool P[MAXN1][MAXN1];
vector<pii > p(3);

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool comp(const pair<int, pii >& A, const pair<int, pii >& B) {
	return A.fi > B.fi;
}

priority_queue< pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;

void dijk(int d) {
	
	dist[d][p[d].fi][p[d].se] = c[p[d].fi][p[d].se];
	pq.push({dist[d][p[d].fi][p[d].se], {p[d].fi, p[d].se}});
	
	memset(P, false, sizeof P);
		
	while(!pq.empty()) {
		int val = pq.top().fi;
		int x = pq.top().se.fi;
		int y = pq.top().se.se;
		pq.pop();
		
		if(P[x][y]) continue;
		P[x][y] = true;
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			if(u < 1 || u > m) continue;
			if(v < 1 || v > n) continue;
			
			if(dist[d][u][v] > val + c[u][v]) {
				dist[d][u][v] = val + c[u][v];
				pq.push({val + c[u][v], {u, v}});
			}
		}
	}
}


signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i = 0; i < 3; ++i) {
		cin >> p[i].fi >> p[i].se;
	}
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> c[i][j];
		}
	}
	
	memset(dist, 0x3f, sizeof dist);
	
	dijk(0);
	dijk(1);
	dijk(2);
	
	int res = inf;
	
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(i == j) continue;
			for(int d = 0; d < 2; ++d) {
				
				int sum = dist[i][p[j].fi][p[j].se] - c[p[i].fi][p[i].se] - c[p[j].fi][p[j].se];
				
				if(d == 0) {
					sum += (dist[i][1][1] + dist[j][m][n]);
				} else {
					sum += (dist[i][m][n] + dist[j][1][1]);
				}
				
				res = min(res, sum);
			}
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}