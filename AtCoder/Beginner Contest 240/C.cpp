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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,x;
bool dp[2][2][MAXN1];
pii a[105];

signed main() {
	fast_cin();
	
	cin >> n >> x;
	dp[0][0][0] = true;
	dp[0][1][0] = true;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
	}
	
	for(int i = 1; i <= n; ++i) {
		
		int cur = i%2;
		
		int u = a[i].fi;
		int v = a[i].se;
		
		for(int val = u; val <= x; ++val) {
			dp[cur][0][val] |= dp[!cur][0][val - u];
		}
		
		for(int val = v; val <= x; ++val) {
			dp[cur][1][val] |= dp[!cur][1][val - v];
		}
		
		for(int val = 1; val <= x; ++val) {
			dp[cur][0][val] = dp[cur][1][val] = (dp[cur][0][val] || dp[cur][1][val]);
		}
		
		memset(dp[!cur], false, sizeof dp[!cur]);
	}
	
	cout << (dp[n%2][0][x] ? "Yes" : "No");
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}