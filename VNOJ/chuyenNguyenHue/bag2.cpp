/*
	Author : vidut_206_CNH
	Link problem: 
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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 255;
const int MAXN2 = 1e6+5;

int m,n;
int dp[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> m;
	dp[0] = 1;
	for(int i=1;i<=m;++i) {
		int x;
		cin >> x;
		for(int w = x; w <= n; ++w) {
			dp[w] += dp[w - x];
		}
	}
	
	cout << dp[n] << "\n";
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock_t() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
