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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int a[2][MAXN1];
int dp[2][MAXN1];
int trace[2][MAXN1];
// 0: right
// 1: down

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < 2; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		
		
		trace[0][1] = -1;
		trace[1][1] = 1;
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1] + a[0][1];
		
		
		for(int j = 2; j <= n; ++j) {
			for(int i = 0; i < 2; ++i) {
				dp[i][j] = inf;
				if(dp[i][j] > dp[i][j - 1] + a[i][j]) {
					dp[i][j] = dp[i][j - 1] + a[i][j];
					trace[i][j] = 0;
				}
				if(i != 0 && dp[i][j] > dp[i - 1][j] + a[i][j]) {
					dp[i][j] = dp[i - 1][j] + a[i][j];
					trace[i][j] = 1;
				}
			}
		}
		int x = 1, y = n;
		while(true) {
			a[x][y] = 0;
			db(x);
			db(y);
			cerr << "\n";
			if(trace[x][y] == 0) {
				--y;
			} 
			else if(trace[x][y] == 1) {
				--x;
			} else break;
		}
		
		memset(dp, 0, sizeof dp);
		
		for(int j = 1; j <= n; ++j) {
			for(int i = 0; i < 2; ++i) {
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
				if(i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
			}
		}
		
		
		cout << dp[1][n] << "\n";
	}	
	

	

	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}