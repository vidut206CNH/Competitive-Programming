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

const int MOD = 998244353;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,k;
int dp[55][2505];

signed main() {
	fast_cin();
	
	cin >> n >> m >> k;
	
	
	memset(dp, 0, sizeof dp);
	
	dp[0][0] = 1;
	
	for(int i = 0; i < n; ++i) {
		for(int w = 0; w <= k; ++w) {
			for(int val = 1; val <= min(k - w, m); ++val) {
				dp[i + 1][w + val] = (dp[i + 1][w + val] + dp[i][w])%MOD;
			}
		}
	}
	int res = 0;
	for(int i = n; i <= k; ++i) {
		res = (res + dp[n][i])%MOD;
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}