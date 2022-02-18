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
const int MAXN1 = 305;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
int a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];

int get(int u, int v, int s, int t) {
	return f[s][t] - f[s][v - 1] - f[u - 1][t] + f[u - 1][v - 1];
}

signed main() {
	fast_cin();
	
	
	cin >> m >> n;
	
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			f[i][j] = f[i - 1][j] + f[i][j - 1] + a[i][j] - f[i - 1][j - 1];
		}
	}
	int res = -inf;
	
	for(int rl = 1; rl < m; ++rl) {
		for(int rr = rl + 1; rr <= m; ++rr) {
			
			int best = get(rl,n,rr,n);
			
			for(int c = n - 1; c >= 1; --c) {
				int cur = get(rl, c, rr, c);
				res = max(res, cur + best);
				best = max(best + a[rl][c] + a[rr][c], cur);			
			}
		}
	}
	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}