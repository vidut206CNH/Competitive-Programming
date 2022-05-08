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

const int MOD = 1e9;
const int MAXN1 = 2e3+5;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int m,n;
int dp[MAXN1];
int C[MAXN1];
int f[MAXN1];


signed main() {
	fast_cin();
	
	cin >> m >> n;
	m = m*2 + 1;
	n = n*2 + 1;
	
	
	// calc C[]
	
	for(int r = 1; r <= min(m,n)/2; ++r) {
		
		for(int h = 0; h <= r; ++h) {
			int d = sqrt(r*r - h*h);
			
			C[r] = (C[r] + 2*d + 1)%MOD;
			
			if(h != 0) C[r] = (C[r] + 2*d + 1)%MOD;
			
		}
/*		db(r);
		db(C[r]);
		cerr << "\n";*/
	}
	
	// calc dp[], f[]
	
	for(int R = 1; R <= min(m,n)/2; ++R) {
		
		dp[R] = 1;
		
		for(int r = 1; r < R; ++r) {
		
			dp[R] = (dp[r]*C[R - r]%MOD + dp[R])%MOD;
		
		}
/*		db(dp[R]);
		cerr << "\n";*/
		f[R] = (f[R - 1] + dp[R])%MOD;
	}
	
	int res = 0;
	
	for(int row = 1; row <= m; ++row) {
		for(int col = 1; col <= n; ++col) {
			int len = min(row - 1, m - row);
			len = min({len, col - 1, n - col});
			//db(row);
			//db(col);
			res = (res + f[len])%MOD;
			//db(res);
			//cerr << "\n";
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}