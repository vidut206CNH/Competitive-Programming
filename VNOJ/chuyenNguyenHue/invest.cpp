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

int m,n;

signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	vector<vector<int> > a(m + 5, vector<int>(n + 5));
		
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	vector< vector<int> > dp(m + 5, vector<int>(n + 5, -inf));
	

	dp[0][0] = 0;
	int res = -inf;
	
	for(int c = 1; c <= n; ++c) {
		for(int val = 1; val <= m; ++val) {
			for(int cur = 0; cur <= val; ++cur) {
				if(dp[val - cur][c - 1] != -inf) dp[val][c] = max(dp[val][c], dp[val - cur][c - 1] + a[cur][c]);
			}
			if(c == n) res = max(res, dp[val][c]);
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}