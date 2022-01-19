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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n,d,k;
//dp[state][level][sum]
int dp[2][MAXN1][MAXN1];
int f[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k >> d;
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	int res = 0;
	
	for(int i=1;i<=n;++i) {
		for(int w=i;w<=n;++w) {
			for(int val = 1;val <= min(w,k);++val) {
				if(val < d) {
					dp[0][i][w] = (dp[0][i-1][w-val] + dp[0][i][w])%MOD;
				}
				else {
					dp[1][i][w] = (dp[1][i][w] + dp[0][i-1][w - val])%MOD; 
				}
				dp[1][i][w] = (dp[1][i][w] + dp[1][i-1][w-val])%MOD;
			}
			if(w==n) res = (res + dp[1][i][w])%MOD;
/*			db(dp[0][i][w]);
			db(dp[1][i][w]);
			cerr << "\n";*/
		}
		//cerr << "\n";
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}