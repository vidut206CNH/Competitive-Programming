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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e9;
int n,m;
int cost[MAXN1];
int M[MAXN1];
int dp[(1 << 12) + 5];

int main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int ss;
		cin >> cost[i] >> ss;
		for(int j = 1; j <= ss; ++j) {
			int x;
			cin >> x;
			--x;
			M[i] |= (1 << x);
		}
	}
	
	
	// DP
	for(int mask = 0; mask < (1 << n); ++mask) dp[mask] = inf;
	dp[0] = 0;
	for(int mask = 0; mask < (1 << n); ++mask) {
		int val = dp[mask];
		for(int i = 1; i <= m; ++i) {
			int mask1 = mask | M[i];
			
			dp[mask1] = min(dp[mask1], val + cost[i]);
		}
	}
	
	int lim = (1 << n) - 1;
	cout << (dp[lim] == inf ? -1 : dp[lim]);
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}