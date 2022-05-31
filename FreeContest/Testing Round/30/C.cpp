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

const long long MOD = 1e9 + 9;
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;

int n,k,m;
int dp[MAXN1][MAXN1];
int C[MAXN1][MAXN1];
string a,b;


long long power(long long X, long long Y) {
	long long res = 1;
	while(Y) {
		if(Y&1) res = res*X%MOD;
		X = X*X%MOD;
		Y /= 2;
	}
	
	return res;
}




int main() {
	fast_cin();
	
	C[0][0] = 1;
	for(int i = 1; i <= 100; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
		}
	}
	
	memset(dp, -1, sizeof dp);	
	
	while(cin >> n >> k >> m) {

		cin >> a >> b;
		a = '0' + a;
		b = '0' + b;
		
		int diff = 0;
		
		for(int i = 1; i <= n; ++i) {
			diff += (a[i] != b[i]);
		}
		
		for(int i = 0; i <= k; ++i) {
			for(int j = 0; j <= n; ++j) {
				dp[i][j] = 0;
			}
		}
		
		dp[0][diff] = 1;
		
		for(int i = 0; i < k; ++i) {
			for(int x = 0; x <= n; ++x) {
				int val = dp[i][x];
				
				for(int d = 0; d <= min(m, x); ++d) {
					if(x + m - 2*d < 0 || x + m - 2*d > n) continue;
					dp[i + 1][x + m - 2*d] = (dp[i + 1][x + m - 2*d] + 1LL*val*C[x][d]%MOD*C[n - x][m - d]%MOD)%MOD;
				}
			}
		}
		
		
		cout << dp[k][0] << "\n";
	}		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}