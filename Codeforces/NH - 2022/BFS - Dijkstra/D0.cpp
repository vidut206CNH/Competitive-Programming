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
const int MAXN1 = 905;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int a,b,c;

int d[MAXN1][MAXN1];

signed main() {
	fast_cin();
	
	cin >> a >> b >> c;
	queue<pii > q;
	q.push({0,0});
	d[0][0] = 1;
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().se;
		
		q.pop();
		if(x == c || y == c) {
			cout << d[x][y] - 1;
			exit(0);
		}
		
		if(d[0][y] == 0) {
			d[0][y] = d[x][y] + 1;
			q.push({0, y});
		}
		
		if(d[x][0] == 0) {
			d[x][0] = d[x][y] + 1;
			q.push({x, 0});
		}
		
		if(d[a][y] == 0) {
			q.push({a, y});
			d[a][y] = d[x][y] + 1;
		}
		if(d[x][b] == 0) {
			q.push({x, b});
			d[x][b] = d[x][y] + 1;
		}
		int val1 = min(a - x, y);
		if(d[val1 + x][y - val1] == 0) {
			d[val1 + x][y - val1] = d[x][y] + 1;
			q.push({val1 + x, y - val1});
		}
		int val2 = min(x, b - y);
		if(d[x - val2][y + val2] == 0) {
			d[x - val2][y + val2] = d[x][y] + 1;
			q.push({x - val2, y + val2});
		}
	}
	
	assert(false);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}