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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int r,c,n;

int ok[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
	fast_cin();
	
	freopen("nazi.inp", "r", stdin);
	freopen("nazi.out", "w", stdout);
	
	cin >> r >> c >> n;
	queue<pii> q;
	for(int i = 1; i <= n; ++i) {
		int u,v;
		cin >> u >> v;
		q.push({u, v});
		ok[u][v] = 1;
	}	
	
	int res = 0;
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;
		
		q.pop();
		res = max(res, ok[x][y]);
		
		for(int i = 0; i < 4; ++i) {
			int u = x + dx[i];
			int v = y + dy[i];
			
			
			if(u < 1 || u > r) continue;
			if(v < 1 || v > c) continue;
			if(ok[u][v]) continue;
			q.push({u, v});
			ok[u][v] = ok[x][y] + 1;
		}		
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}