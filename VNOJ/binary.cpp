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



const int MOD = 1e9 + 7;
const int MAXN1 = 40;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[MAXN1];
int dp[MAXN1][MAXN1][2][2];
// f(i, lower, j, positive)



signed main() {
	fast_cin();
	
	while(cin >> n >> k) {	
		
		
		
		vector<int> bits;
		if(n == 0) bits.push_back(0);			
		while(n) {
			bits.push_back(n%2);
			n /= 2;
		}
	
		reverse(bits.begin(), bits.end());
		for(int i = 0; i < sz(bits); ++i) {
			a[i + 1] = bits[i];
		}
		
		int lim = sz(bits);
		
		if(k > lim) {
			cout << "0\n";
			continue;
		}
		
		// DP
		
		memset(dp, 0, sizeof dp);
		dp[0][0][0][0] = 1;
		
		for(int i = 0; i < lim; ++i) {
			for(int j = 0; j <= i; ++j) {
				for(int lower = 0; lower  < 2; ++lower) {
					for(int positive = 0; positive < 2; ++positive) {
						
						int cur = dp[i][j][lower][positive];
						
						for(int digit = 0; digit  < 2; ++digit) {
							
							if(digit > a[i + 1] && lower == 0) continue;
							
							bool lower2 = (lower || digit < a[i + 1]);
							bool positive2 = (positive || digit > 0);
							int j2 = j;
							
							if(positive && digit == 0) j2++;
							
							dp[i + 1][j2][lower2][positive2] += cur;
						}
					}
				}
			}
		}
		
		
		int res = 0;
		for(int lower = 0; lower < 2; ++lower) {
			res += dp[lim][k][lower][true];
		}
		
		if(k == 1) res++;
		
		cout << res << "\n";
	
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}