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


int dp[3][MAXN1];

signed main() {
	fast_cin();
	
	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;
	
	int n;
	cin >> n;
	int res = 0;
	
	for(int i = 2; i <= n; ++i) {
		for(int state = 0; state <= 2; ++ state) {
			if(state == 1) {
				dp[state][i] = (dp[0][i - 1] + dp[2][i - 1])%MOD;
			} else {
				dp[state][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1])%MOD;
			}
			if(i == n) res = (res + dp[state][i])%MOD;
		}
	}	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}