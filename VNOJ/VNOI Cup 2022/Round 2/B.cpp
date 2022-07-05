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
const int MAXN1 = 3004;
const int MAXN2 = 1e6+5;

int n,m,k;
long long a[MAXN1][15];
long long dp[MAXN1][MAXN1];

int main() {
	fast_cin();
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	
	
	dp[0][0] = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int w = 0; w <= k; ++w) {
			long long sum = 0;
			for(int u = 0; u <= m && w + u <= k; ++u) {
				sum += a[i + 1][u];
				dp[i + 1][u + w] = max(dp[i][w] + sum, dp[i + 1][u + w]);
			} 
		}
	}
	
	cout << dp[n][k];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}