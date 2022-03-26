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
const int MAXN1 = 405;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,k,s;
int f[MAXN1][MAXN1];
int d[MAXN1][MAXN1];
int b[MAXN1];
int pre[MAXN1];

signed main() {
	fast_cin();
	
	cin >> m >> n >> k >> s;
	for(int i = 1; i <= k; ++i) {
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		f[x][y]++;
		f[x][v + 1]--;
		f[u + 1][y]--;
		f[u + 1][v + 1]++;
	}
	
	int best = -inf;
	int res = 0;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			if(f[i][j] == s - 1) d[i][j] = 1;
			if(f[i][j] == s) d[i][j] = -1;
			res += (f[i][j] == s);
			
			//cerr << f[i][j] << " \n"[j == n];
		}
	}
	
	
	
	for(int r1 = 1; r1 <= m; ++r1) {
		memset(b, 0, sizeof b);
		for(int r2 = r1; r2 <= m; ++r2) {
			
			for(int c = 1; c <= n; ++c) {
				b[c] += d[r2][c];
				pre[c] = pre[c - 1] + b[c];	
			}
			
			int minn = 0;
			
			for(int c = 1; c <= n; ++c) {
				best = max(pre[c] - minn, best);
				minn = min(pre[c], minn);
			}
			
		}
	}
	
	
	cout << res + best;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}