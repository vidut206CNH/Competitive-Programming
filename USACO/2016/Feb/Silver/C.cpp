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

int d[MAXN1][MAXN1];
int m,k,sx,sy;

signed main() {
	fast_cin();
	
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	
	memset(d, -1, sizeof d);
	
	cin >> sx >> sy >> k >> m;
	d[0][0] = 0;
	queue<pii > q;
	q.push({0, 0});
	
	int res = inf;
	
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;
		
		q.pop();
		
		
		if(d[x][y] > k) break;
		
		
		res = min(res, abs(m - x - y));
/*		db(x);
		db(y);
		db(res);
		cerr << "\n";*/
		
		if(d[sx][y] == -1) {
			d[sx][y] = d[x][y] + 1;
			q.push({sx, y});
		}
		
		if(d[x][sy] == -1) {
			d[x][sy] = d[x][y] + 1;
			q.push({x, sy});
		}
		
		if(d[0][y] == -1) {
			d[0][y] = d[x][y] + 1;
			q.push({0, y});
		}
		
		if(d[x][0] == -1) {
			d[x][0] = d[x][y] + 1;
			q.push({x, 0});
		}
		
		int g1 = min(x,sy - y);
		
		if(d[x - g1][y + g1] == -1) {
			d[x - g1][y + g1] = d[x][y] + 1;
			q.push({x - g1, y + g1});
		}
		
		int g2 = min(sx - x, y);
		if(d[x + g2][y - g2] == -1) {
			d[x + g2][y - g2] = d[x][y] + 1;
			q.push({x + g2, y - g2});
		}
		 
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}