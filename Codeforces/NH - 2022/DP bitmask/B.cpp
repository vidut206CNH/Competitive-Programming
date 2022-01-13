/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int MAXN1 = 1LL << 10;
const int MAXN2 = 1e6+5;
const int inf = 1e9;

int n,m;
int dp[15][MAXN1];
bool a[10][10];



signed main() {
	fast_cin();
	
	cin >> n >> m;
	int lim = 1 << n;
	
	for(int i=1;i<=m;++i) {
		int u,v;
		cin >> u >> v;
		--u;
		--v;
		a[u][v] = 1;		
	}
	memset(dp, 0, sizeof dp);
	for(int i=0;i<lim;++i) dp[0][i] = 1;
	
	for(int i=1;i<=n;++i) {
		for(int mask=0;mask < lim;++mask) {
			if(__builtin_popcount(mask) != i-1) continue;
			for(int p=0;p<n;++p) {
				
				if(mask >> p & 1) continue;
				bool bad = 0;
				for(int k=0;k<n;++k) {
					if(a[k][p] && !(mask >> k & 1)) {
						bad = 1;
						break;
					}
				}
				if(!bad) dp[i][mask | (1 << p)] = (dp[i][mask | (1 << p)] + dp[i-1][mask])%MOD;
/*				db(mask);
				db(i);
				db(dp[i][mask]);
				cerr << "\n";*/
			} 
		}
		
	}	
	
	cout << dp[n][lim - 1];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}